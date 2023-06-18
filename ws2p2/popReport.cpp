/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 2.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Region.h"

int main()
{
	// Test 1
	std::cout << "T1: Load Some Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (sdds::load("toronto.csv"))
		sdds::display("Toronto");

	// Test 2: Discard old data, load new data
	std::cout << "\nT2: Discard Old Data; Load New Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	sdds::cleanUp();
	if (sdds::load("canada.csv"))
		sdds::display("Canada", true);

	sdds::cleanUp();

	return 0;
}
