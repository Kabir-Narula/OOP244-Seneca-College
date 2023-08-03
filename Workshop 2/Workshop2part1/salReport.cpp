/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 1
// Version 2.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Kabir NArula    23 May 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Employee.h"

int main()
{
	// Test 1
	std::cout << "T1: Load Some Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (sdds::load("employees.csv"))
		sdds::display();

	// Test 2: Discard old data, load new data
	std::cout << "\nT2: Discard Old Data; Load New Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	sdds::deallocateMemory();
	if (sdds::load("simpsons.csv"))
		sdds::display(false);

	// Test 3: load some more, add to the existing collection
	std::cout << "\nT3: Load More Data; Add to the Existing Collection\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (sdds::load("employees.csv"))
		sdds::display(true);

	// clean-up
	sdds::deallocateMemory();
}
