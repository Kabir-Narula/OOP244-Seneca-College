//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 06/06/2023(Thursday)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Canister.h"
#include <cmath>


using namespace std;

namespace sdds
{

	double Canister::getCapacity() const
	{
		double capacity = 0.0;

		capacity = 3.14159265 * (this->m_height - 0.267) * pow((this->m_diameter / 2), 2);

		return capacity;
	}

	//PUBLIC

	//! Constructor
	Canister::Canister()
	{
		this->m_contentName = nullptr;
		this->m_height = 13.0;
		this->m_diameter = 10.0;
		this->m_contentVolume = 0.0;
		this->m_usable = true;
	}

	Canister::Canister(double diameter, double height) : Canister()
	{
		// Check if both parameters are valid
		if (diameter >= 10.0 and diameter <= 30.0 and height >= 10.0 and height <= 40.0)
		{
			// Set the diameter and height attributes
			m_diameter = diameter;
			m_height = height;
			m_usable = true;
		}
	}



	Canister::Canister(const char* contentName, double contentVolume) : Canister()
	{
		pour(contentName, contentVolume);
	}

	Canister::Canister(double diameter, double height, const char* contentName, double contentVolume) : Canister(diameter, height)
	{
		pour(contentName, contentVolume);
	}



	//!Destructor
	Canister::~Canister()
	{
		delete[] m_contentName;
	}



	Canister& Canister::pour(const char* what, double howMuch)
	{
		/*
		if the canister is usable, the `what` is not null and not an empty string, and
		`howMuch` is more than 0
		*/
		if (this->m_usable == true && what != nullptr && what[0] != '\0' && howMuch > 0.0)
			//! If 'what' is not null and the first element is not \0, 
			//! this means that the string has something inside, but we dont know
		{
			/*
			if the canister is empty (the name is not set), allocate dynamic memory
			for `m_contentName` and copy into it the content of the `what` parameter.
			*/
			if (this->m_contentName == nullptr)
			{
				// Deallocate
				delete[] this->m_contentName; //! Safe guard

				// Allocate dynamic memory for m_contentName
				this->m_contentName = new char[strlen(what) + 1];

				// Copy the content of what into m_contentName
				strcpy(this->m_contentName, what);
			}

			/*
			if `howMuch` is less than or equal to the available capacity, add
			`howMuch` to the `m_contentVolume`
			if `howMuch` is more than the available capacity, fill the canister
			to capacity.
			*/
			if (howMuch <= getCapacity())
			{
				this->m_contentVolume += howMuch;
			}
			else
			{
				this->m_contentVolume = getCapacity();
			}

			/*
			- if `what` is different from `m_contentName`, then:
			- dynamically create a new C-string to store the value
			  "Mix of [CONTENT_NAME] and [WHAT]"
			- delete the old content name
			- store the address of the new string in the `m_contentName` pointer
			- set the canister to not usable
			*/
			if (strcmp(what, this->m_contentName) != 0)
			{
				// Create a new C-string for the mixed content name
				const char* mixedContent = " Mix of [";
				size_t mixedContentLen = strlen(mixedContent);
				size_t whatLen = strlen(what);
				size_t nameLen = strlen(m_contentName);
				size_t newNameLen = mixedContentLen + whatLen + 10 + nameLen; // 10 for " and "

				char* newContentName = new char[newNameLen];
				strcpy(newContentName, mixedContent);
				strcat(newContentName, this->m_contentName);

				strcat(newContentName, "] and [");
				strcat(newContentName, what);
				strcat(newContentName, "]");

				// Delete the old content name
				delete[] this->m_contentName;

				// Update m_contentName with the new string
				this->m_contentName = newContentName;

				// Set the canister to not usable
				this->m_usable = false;
			}
		}
		return *this;
	}


	Canister& Canister::pour(Canister& src)
	{
		// Both canisters are usable
		if (m_usable && src.m_usable)
		{
			// Calculate how much content can be transferred
			double transferAmount = min(getCapacity() - m_contentVolume, src.m_contentVolume);

			// Add content to the current instance
			pour(src.m_contentName, transferAmount);

			// Remove the transferred content from the parameter
			src.m_contentVolume -= transferAmount;

			// If all content from src was transferred, empty and wash it
			if (src.m_contentVolume == 0)
				src.emptyAndWash();
		}

		// Return a reference to the current instance
		return *this;
	}


	void Canister::emptyAndWash()
	{
		// Deallocate dynamic memory used by the current instance
		delete[] this->m_contentName;

		// Set content name to null
		this->m_contentName = nullptr;

		// Set content volume to 0
		this->m_contentVolume = 0;

		// The canister is usable
		this->m_usable = true;
	}

	ostream& Canister::display(ostream& out) const
	{
		int originalPrecision = out.precision();
		auto originalFill = out.fill();
		ios_base::fmtflags originalFlags = out.flags();

		out.precision(1);
		out.setf(ios::fixed);

		out.width(8);
		out.fill(' ');
		out << getCapacity() << "cc (";
		out.width(3);
		out.fill(' ');
		out << this->m_height << "x";
		out.width(3);
		out.fill(' ');
		out << this->m_diameter << ") canister of ";

		if (this->m_usable)
		{
			out.width(8);
			out.fill(' ');
			out << this->m_contentVolume << "cc";
			if (this->m_contentName and this->m_contentName[0] != '\0')
			{
				out << "  " << this->m_contentName;
			}
		}
		else {
			out.width(8);
			out.fill(' ');
			out << this->m_contentVolume << "cc " << this->m_contentName << " -> unusable content. Discard and wash!";
		}

		out.precision(originalPrecision);
		out.flags(originalFlags);
		out.fill(originalFill);

		return out;
	}

}