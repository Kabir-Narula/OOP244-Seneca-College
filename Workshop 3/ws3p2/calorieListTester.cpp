// Workshop 3: 
// Version: 1
// Date: 2023/05
// Author: Fardad Soleimanloo
// Update: Cornel
// Description:
// This file tests the DIY section of your workshop
// Do not modify this code when submitting
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Food.h"
#include "Food.h" // intentional
#include "CalorieList.h"
#include "CalorieList.h" //intentional

// Checking if header guards exist and follow convention.
#ifndef SDDS_FOOD_H
#error "The header guard for 'Food.h' doesn't follow the convention!"
#endif

#ifndef SDDS_CALORIELIST_H
#error "The header guard for 'CalorieList.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention


const int c_breakfast = 1; // the food will be consumed at breakfast
const int c_lunch = 2; // the food will be consumed at lunch
const int c_dinner = 3; // the food will be consumed at dinner
const int c_snack = 4; // the food will be consumed as a snack


/// <summary>
/// Prints a string, an integer, and a floating point number to the screen
///   using current formatting options (alignment & precision).
/// </summary>
/// <param name="title"></param>
void checkOutputFormatting(const char* title)
{
	std::cout << title << "\n";
	std::cout << "==========:==========:==========:==========:==========\n";

	// check filling character and alignment for strings
	std::cout << '*';
	std::cout.width(52);
	std::cout << "ABC" << "*\n";

	// check formatting for floating point numbers
	std::cout << '*';
	std::cout.width(52);
	std::cout << 1.23456789 << "*\n";

	// check formatting for integers
	std::cout << '*';
	std::cout.width(52);
	std::cout << 123 << "*\n";
}

int main()
{
	// change the filling character
	std::cout.fill('*');

	// checking the default formatting options
	checkOutputFormatting("T1: Default output formatting options");

	sdds::CalorieList theList;

	{
		// TEST: Too few items in the bill
		std::cout << "\n\nT2: An incomplete list  --->   # items < capacity\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		theList.init(6);
		theList.add("Cheerios cereal with 2% milk", 170, c_breakfast);
		theList.display();
	}

	{
		// after student's code printed some data, check
		//   if the formatting options are the same or
		//   were side effects (should not be side effects)
		checkOutputFormatting("\n\nT3: Current output formatting options");
		std::cout.fill('#');
		std::cout.precision(10);
	}

	{
		// TEST: Bad items in the list
		std::cout << "\n\nT4: An invalid list  --->   bad food items\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		theList.add(nullptr, 100, c_breakfast);
		theList.add("Cheeseburger", 303, c_lunch);
		theList.add("Pepsi", 150, 0);
		theList.add("Apple", 52, c_snack);
		theList.add("Cake", 3001, c_dinner);
		theList.display();
		theList.reset();
	}

	{
		// TEST: A good list
		std::cout << "\n\nT5: A good list\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		theList.init(9);
		theList.add("Cheerios cereal with 2% milk", 170, c_breakfast);
		theList.add("Tim Hortons medium coffee double double", 230, c_breakfast);
		theList.add("Cheeseburger", 303, c_lunch);
		theList.add("French fries", 312, c_lunch);
		theList.add("Pepsi", 150, c_lunch);
		theList.add("Apple", 52, c_snack);
		theList.add("Bread and cheese", 195, c_dinner);
		theList.add("Garden salad with dressing", 220, c_dinner);

		if (!theList.add("Red wine", 85, c_dinner))
			std::cout << "This should not be printed!\n";

		if (theList.add("This should not be added", 100, c_dinner))
			std::cout << "This should not be printed!\n";

		theList.display();
		theList.reset();
	}

	{
		// TEST: Dynamic memory allocation
		std::cout << "\n\nT6: Dynamic memory allocation\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		theList.init(25);

		for (int i = 0; i < 25; i++)
			theList.add("Tim Hortons medium coffee double double", 200 + i * 123 % 17, i % 4 + 1);

		const auto& cref = theList;
		cref.display(); // if compilation error here, make sure the "display()" is a query.

		theList.reset();
	}

	{
		// Cheching the output formatting options again for side effects.
		checkOutputFormatting("\n\nT7: Current output formatting options");
		std::cout.fill('#');
		std::cout.precision(10);
	}

	return cout;
}
