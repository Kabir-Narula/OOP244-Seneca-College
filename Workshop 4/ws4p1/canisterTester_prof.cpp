// Workshop 4:
// Version: 0.9
// Date: 2021/02/04
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Canister.h"
#include "Canister.h"

// Checking if header guards exist and follow convention.
#ifndef SDDS_CANISTER_H
#error "The header guard for 'Canister.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention

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


void showCans(const char* title, const sdds::Canister* canArray, int num)
{
}


int main()
{
	{
		// change the filling character
		std::cout.fill('0');

		// checking the default formatting options
		checkOutputFormatting("T1: Default output formatting options");
	}

	sdds::Canister canCol[] = {
	   sdds::Canister(),                             // default size
	   sdds::Canister(100,  20),                     // bad diameter, default size
	   sdds::Canister(5  ,  20),                     // bad diameter, default size
	   sdds::Canister(20 ,   5),                     // bad height, default size
	   sdds::Canister(20 , 100),                     // bad height, default size
	   sdds::Canister(30 ,  40),                     // OK
	   sdds::Canister(nullptr, 123.456),             // bad name, empty, default size
	   sdds::Canister("Orange Juice", 0),            // bad qty, empty,default size
	   sdds::Canister("Orange Juice", 123.456),      // OK
	   sdds::Canister(9, 20,  "Olive Oil", 321.456), // bad diameter, default size
	   sdds::Canister(20, 9,  "Water", 321.456),     // bad height,   default size
	   sdds::Canister(20, 20, "", 321.456),          // bad name, empty
	   sdds::Canister(20, 20, "Olive Oil", 0),       // bad qty, empty
	   sdds::Canister(20, 20, "Olive Oil", 321.456), // OK
	   sdds::Canister(15, 20, "Milk", 4321.456),     // too much milk
	   sdds::Canister(10, 10, "Gasoline", 456.321),  // OK
	   sdds::Canister("Orange Juice", 578.456),      // OK
	   sdds::Canister("Olive Oil",    578.456),      // OK
	   sdds::Canister(20, 20, "Olive Oil", 321.456), // OK
	   sdds::Canister(20, 20, "Olive Oil", 321.456), // OK
	};

	{
		std::cout << "\nT2: Checking constructors\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		std::cout << "  #   Capacity  Dimensions               Volume     Content\n";
		std::cout << "----  ---------------------------------  ---------  ---------------------------\n";
		for (int i = 0; i < 20; i++)
		{
			std::cout.width(3);
			std::cout << i + 1 << ". ";
			canCol[i].display() << "\n";
		}
		std::cout << "-------------------------------------------------------------------------------\n";

	}

	{
		std::cout << "\nT3: Checking Canister::pour" << "\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		canCol[0].pour("Spagetti Sauce", 700);                // make a canister with sauce         -> OK
		canCol[0].display() << "\n";                          // OK (sauce)
		canCol[0].pour("Spagetti Sauce", 200);                // add more sauce                     -> OK
		canCol[0].display() << "\n";                          // OK (sauce)
		canCol[1].pour("Yogurt with strawberry flavor", 100); // make another canister with yogurt  -> OK
		canCol[1].display() << "\n";                          // OK (yogurt)
		canCol[0].pour(canCol[1]);                            // mix sauce with yogurt              -> unusable
		canCol[0].display() << "\n";                          // unusable
		canCol[1].display() << "\n";                          // empty
		canCol[1].pour(canCol[0]);                            // no effect (can[0] is unusable)
		canCol[0].display() << "\n";                          // unusable
		canCol[1].display() << "\n";                          // empty
		canCol[0].emptyAndWash();                             // ...
		canCol[0].display() << "\n";                          // empty
		canCol[0].pour("Apple Cider", 876);
		canCol[0].display() << "\n";                          // OK (apple)
		canCol[1].pour(canCol[0]);
		canCol[0].display() << "\n";                          // empty
		canCol[1].display() << "\n";                          // OK (apple)
		canCol[5].pour("Apple Cider", 123456.1);
		canCol[5].display() << "\n";                          // OK (apple)
		canCol[1].pour(canCol[5]);
		canCol[1].display() << "\n";                          // OK (apple)
		canCol[5].display() << "\n";                          // OK (apple)
		canCol[5].pour(canCol[13]);
		canCol[5].display() << "\n";                          // unusable
		canCol[13].display() << "\n";                         // OK (olive oil)
	}

	{
		// checking the current formatting options
		checkOutputFormatting("\nT4: Current output formatting options");
	}

	return cout;
}

