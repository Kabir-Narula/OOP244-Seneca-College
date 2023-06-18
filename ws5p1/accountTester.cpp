
#include <iostream>
#include "Account.h"
#include "Account.h"

// Checking if header guards exist and follow convention.
#ifndef SDDS_ACCOUNT_H
#error "The header guard for 'Account.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention

int main()
{
	sdds::Account mixed[]
	{
		{"John",       111111,  111.111},
		{"Jane",       222222,  222.222},
		{                              },   // invalid, everything is missing
		{"Vanessa",     33333,  333.333},   // Vanessa is the holder, bad number (reject ballance and number)
		{"",           444444, 4444.444},   // invalid, bad name
		{"Dan",        555555          },   // OK, no money
		{"Sarah",      666666,  -66.666},   // OK, owes money
		{"Michael",    777777,  777.777},
		{nullptr,      888888,  888.888},   // invalid, bad name (set to empty)
		{"Allie",           0,  999.999},   // Allie is the holder, reject the balance since the account is not set yet
	};

	{
		std::cout << "T1: Checking constructors\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		std::cout << "| Name       |   Number |    Balance |\n"
			<< "--------------------------------------\n";
		for (int i = 0; i < 10; ++i)
			mixed[i].display();
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT2: Testing conversion operators\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		for (int i = 0; i < 10; ++i)
		{
			if ((bool)mixed[i] == !mixed[i])
				std::cout << "ERROR: keep working on your code.\n";
			if (mixed[i]) // conversion-to-bool
			{
				const char* name = (const char*)mixed[i];
				int number = (int)mixed[i];
				double balance = (double)mixed[i];
				std::cout << "|" << name << "|" << number << "|" << balance << "|\n";
			}
		}
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT3: Testing the assignment operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		std::cout << "| Name       |   Number |    Balance |\n"
			<< "--------------------------------------\n";
		sdds::Account acc;
		acc.display();
		acc = 12.34;     // no name, cannot set
		acc.display();
		acc = 123456;    // no name, cannot set
		acc.display();
		acc = "Tom";     // OK
		acc.display();
		acc = 1234.5678; // no number, cannot set
		acc.display();
		acc = 12345;     // bad number
		acc.display();
		acc = 1234567;   // bad number
		acc.display();
		acc = 123456;    // OK
		acc.display();
		acc = 987.65432; // OK
		acc.display();
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT4: Testing the increment operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		std::cout << "| Name       |   Number |    Balance |\n"
			<< "--------------------------------------\n";
		sdds::Account acc("Cornel", 123456, -500.0); // OK account
		acc.display();
		(++acc).display(); // 1000 more than in previous line
		acc.display();     // same as in previous line
		(acc++).display(); // same as in previous line
		acc.display();     // 1000 more than in previous line
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT5: Testing addition operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		std::cout << "Should be  0 -> " << (mixed[3] + mixed[6]) << "\n";
		std::cout << "Should be  0 -> " << (mixed[4] + mixed[3]) << "\n";
		std::cout << "Should be OK -> " << (mixed[6] + mixed[5]) << "\n";
		std::cout << "Should be OK -> " << (mixed[6] + mixed[7]) << "\n";
		std::cout << "Should be  0 -> " << (mixed[4] + 100.0) << "\n";
		std::cout << "Should be  0 -> " << (100.0 + mixed[4]) << "\n";
		std::cout << "Should be OK -> " << (mixed[7] + 100.0) << "\n";
		std::cout << "Should be OK -> " << (100.0 + mixed[7]) << "\n";
		std::cout << "Should be OK -> " << (100.0 + mixed[0] + 100.0 + mixed[1] + mixed[5]) << "\n";
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT6: Testing addition-assignment operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		(mixed[6] += 50).display();
		mixed[6].display();          // same as previous line
		double val = 1000;
		val += mixed[6];
		mixed[6].display();          // same as previous line
		std::cout << "Val = [" << val << "]\n";
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT7: Testing comparison operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		std::cout << "Checking same name: " << (mixed[0] == "Dan" ? "true" : "false") << '\n';    // false
		std::cout << "Checking same name: " << (mixed[0] == "John" ? "true" : "false") << '\n';   // true
		std::cout << "Checking same number: " << (mixed[0] == 111112 ? "true" : "false") << '\n'; // false
		std::cout << "Checking same number: " << (mixed[0] == 111111 ? "true" : "false") << '\n'; // true
		std::cout << "--------------------------------------\n";
	}

	{
		std::cout << "\nT8: Testing insertion/extraction operators\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << "--------------------------------------\n";
		std::cout << "| Name       |   Number |    Balance |\n"
			<< "--------------------------------------\n";
		sdds::Account acc1("Cornel", 123456, 500.0);   // OK account
		sdds::Account acc2("Vanessa", 654321, 5000.0); // OK account
		acc1.display(); //  500
		acc2.display(); // 5000
		(acc1 << acc1).display(); // no change, print acc1
		(acc2 >> acc2).display(); // no change, print acc2
		acc1.display(); //  500
		acc2.display(); // 5000
		acc1 << acc2;   // transfer everything into acc1
		acc1.display(); // 5500
		acc2.display(); //    0
		acc1 >> acc2;   // transfer everything into acc2
		acc1.display(); //    0
		acc2.display(); // 5500
		std::cout << "--------------------------------------\n";
	}

	return cout;
}
