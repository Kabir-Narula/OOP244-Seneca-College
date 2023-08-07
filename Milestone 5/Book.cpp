/* Citation and Sources...
Final Project Milestone 5
Module: Book.cpp
Filename: Book.cpp
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/08  Preliminary release
2023/02/08  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string> 
#include <iomanip>
#include "Lib.h"
#include "Book.h"
using namespace std;
namespace sdds
{
	Book::Book()
	{
		m_authorName = nullptr;
	}
	Book::Book(const Book& B) : Publication(B)
	{
		m_authorName = nullptr;
		*this = B;
	}
	Book& Book::operator=(const Book& B)
	{
		//checks for self assignment
		if (this != &B)
		{
			Publication::operator=(B);
			delete[] m_authorName;

			//allocate memory for the authorname and copy the content
			if (B.m_authorName != nullptr)
			{
				//delete[] m_authorName;
				m_authorName = new char[strlen(B.m_authorName) + 1];
				strcpy(m_authorName, B.m_authorName);
			}
		}
		else
			m_authorName = nullptr;
		return *this;
	}
	Book::~Book()
	{
		delete[] m_authorName;
		m_authorName = nullptr;
	}


	//Methods
	char Book::type()const
	{
		return 'B';
	}
	std::ostream& Book::write(std::ostream& os) const
	{
		//invoking the write of the base class
		Publication::write(os);

		//if the incoming argument is a console IO object
		if (conIO(os))
		{
			os << ' ';
			if (m_authorName and strlen(m_authorName) > SDDS_AUTHOR_WIDTH)
			{
				os.write(m_authorName, SDDS_AUTHOR_WIDTH);
			}
			else
			{
				os.width(SDDS_AUTHOR_WIDTH);
				os.setf(ios::left);
				os << this->m_authorName;
				os.unsetf(ios::left);
			}
			os << " |";
		}
		else
		{
			os << '\t' << m_authorName;
		}
		return os;
	}
	std::istream& Book::read(std::istream& is)
	{
		char authorNameInput[257]{};
		//invoke the read of the Base class
		Publication::read(is);
		//free the memory held for the author's name
		delete[] m_authorName;
		m_authorName = nullptr;

		//If the incoming argument is a console IO object
		if (conIO(is))
		{
			//ignore one character(skip the '\n')
			is.ignore(3000, '\n');

			//prompt
			cout << "Author: ";
			is.getline(authorNameInput, 257, '\n');
		}
		else
		{
			is.ignore();
			is.get(authorNameInput, 257, '\n');
		}

		m_authorName = new char[strlen(authorNameInput) + 1];
		strcpy(m_authorName, authorNameInput);

		return is;
	}
	void Book::set(int memberId)
	{
		// Invoke the set of the base class to set the member id.
		Publication::set(memberId);
		// Reset the date to the current date.
		resetDate();

	}
	Book::operator bool() const
	{
		if (m_authorName != nullptr && m_authorName[0] != '\0' and Publication::operator bool() == true)
		{
			return true;
		}
		return false;
	}

}