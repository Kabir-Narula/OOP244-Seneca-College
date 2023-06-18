
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"

using namespace std;
namespace sdds
{
	//! Default Constructor


	Mark::Mark(int value)
	{
		if (value >= 0 and value <= 100)
		{
			this->m_mark = value;
		}
		else
		{
			this->m_mark = -1;
		}
	}


	//! Define the addition-assignment operator
	Mark& Mark::operator+=(int value)
	{
		if (m_mark >= 0 and m_mark <= 100)
		{
			m_mark += value;

			//// Ensure the mark stays within the valid range [0, 100]
			//if (m_mark < 0)
			//	m_mark = 0;
			//else if (m_mark > 100)
			//	m_mark = 100;
		}
		else
		{
			m_mark = -1;
		}
		return *this;
	}

	//! Define the assignment operator
	Mark& Mark::operator=(char* name)
	{
		int mark = 0;
		int sign = 1;
		int i = 0;

		// Check if the mark is negative
		if (name[0] == '-')
		{
			sign = -1;
			i = 1;
		}

		// Parse the mark string
		for (i = 0; name[i] != '\0'; ++i)
		{
			if (name[i] >= '0' && name[i] <= '9')
			{
				mark = mark * 10 + (name[i] - '0');
			}
			else
			{
				// Invalid character encountered, mark remains 0
				mark = 0;
				break;
			}
		}

		// Apply the sign to the mark value
		mark *= sign;

		// Check if the mark is within the valid range
		if (mark >= 0 && mark <= 100)
		{
			m_mark = mark;
		}
		else
		{
			m_mark = -1;
		}
		return *this;
	}


	//! Conversion to int
	Mark::operator int() const
	{
		if (m_mark >= 0 and m_mark <= 100)
			return m_mark;
		else
			return 0;
	}

	//! Conversion to char
	Mark::operator char() const
	{
		char grade;

		if (m_mark >= 0 && m_mark <= 49)
			grade = 'F';
		else if (m_mark >= 50 && m_mark <= 59)
			grade = 'D';
		else if (m_mark >= 60 && m_mark <= 69)
			grade = 'C';
		else if (m_mark >= 70 && m_mark <= 79)
			grade = 'B';
		else if (m_mark >= 80 && m_mark <= 100)
			grade = 'A';
		else
			grade = 'X';

		return grade;
	}



	//! Conversion to double
	Mark::operator double() const
	{
		double gpa = 0.0;

		if (m_mark >= 0 && m_mark <= 49)
			gpa = 0.0;
		else if (m_mark >= 50 && m_mark <= 59)
			gpa = 1.0;
		else if (m_mark >= 60 && m_mark <= 69)
			gpa = 2.0;
		else if (m_mark >= 70 && m_mark <= 79)
			gpa = 3.0;
		else if (m_mark >= 80 && m_mark <= 100)
			gpa = 4.0;
		else
			return 0.0;

		return gpa;

		/*	if (m_mark >= 0 && m_mark <= 100)
				return 4.0 - (m_mark - 50) / 10.0;
			else
				return 0.0;*/
	}

	//! Addition-assignment operator overload
	int& operator+=(int& val, const Mark& theMark)
	{
		if (&theMark)
			val += theMark.operator int();
		return val;
	}
}
