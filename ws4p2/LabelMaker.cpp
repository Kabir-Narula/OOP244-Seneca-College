
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Label.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds
{
	/// Creates a dynamically allocated array of objects of type
	///   `Label` of size specified as a parameter. Stores the
	///   address of the array in an attribute and manages it.
	LabelMaker::LabelMaker(int noOfLabels)
	{
		m_noOfLabels = noOfLabels;

		m_label = new Label[m_noOfLabels];

	}

	void LabelMaker::readLabels()
	{
		if (m_noOfLabels > 0)
		{
			cout << "Enter " << m_noOfLabels << " labels:" << endl;

			for (int i = 0; i < m_noOfLabels; i++)
			{
				cout << "Enter label number " << i + 1 << " > ";
				m_label[i].readLabel();

			}
		}
	}


	void LabelMaker::printLabels() const // call Label display function call
	{
		// Print all the fucntion, 
		// Using for loop to call the Label, this function will call all the label
		for (int i = 0; i < m_noOfLabels; ++i)
		{
			m_label[i].print();
			cout << endl;
		}
	}


	//! Destructor
	LabelMaker::~LabelMaker()
	{

		delete[] m_label;
		m_label = nullptr;
	}


}
