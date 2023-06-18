//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 13/06/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Label.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds
{
	//! Constructor
	Label::Label()
	{
		strcpy(m_frame, "+-+|+-+|");
		m_label = nullptr;

	}

	Label::Label(const char* frame) : Label()
	{
		strcpy(m_frame, frame);

	}


	Label::Label(const char* frame, const char* content) : Label()
	{
		strcpy(m_frame, frame);

		//Deallocate
		delete[] m_label;  //!Safe guard


		if (strlen(content) <= 70)
		{
			// Allocate dynamic memory for the content
			m_label = new char[strlen(content) + 1];

			// Copy the content into m_content;
			strcpy(m_label, content);

		}
	}


	//! Destructor
	Label::~Label()
	{
		delete[] m_label;
		m_label = nullptr;
	}


	void Label::readLabel()
	{
		// Read all the function 
		// Allocate memory for each container
		// Read the number of label , total of 6
		char content[71]; // 70 is the max + \0
		if (m_label)  //!Safeguard
		{
			delete[] m_label;
			m_label = nullptr;
		}


		cin.get(content, 71);   //70 is the max + \0  

		cin.ignore(10000, '\n');

		int size = strlen(content);

		m_label = new char[size + 1];

		strcpy(m_label, content);

	}


	ostream& Label::print() const
	{
		// Print frame + label
		if (m_label)
		{
			cout << m_frame[0];
			cout.width(strlen(m_label) + 3);
			cout.fill(m_frame[1]);
			cout << m_frame[2] << endl;

			cout << m_frame[7];
			cout.width(strlen(m_label) + 3);
			cout.fill(' ');
			cout << m_frame[3] << endl;

			cout << m_frame[7];
			cout << ' ' << m_label << ' ';
			cout << m_frame[3] << endl;

			cout << m_frame[7];
			cout.width(strlen(m_label) + 3);
			cout.fill(' ');
			cout << m_frame[3] << endl;

			cout << m_frame[6];
			cout.width(strlen(m_label) + 3);
			cout.fill(m_frame[5]);
			cout << m_frame[4];
		}
		return cout;

	}
}