//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 11/07/2023(Tuesday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include<iostream>
#include "Truck.h"
#include "Truck.h" // intentional
#include "MotorVehicle.h"
#include "MotorVehicle.h" // intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(40);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(40);
	cout << "" << endl;
	cout.fill(oldFill);
}

void moveAndLoad(Truck& aTruck, const char* destination, double cargo)
{
	//cout << aTruck << endl;
	aTruck.moveTo(destination);
	if (aTruck.addCargo(cargo))
		cout << "Cargo loaded!\n";
	else
		cout << "Adding cargo failed!\n";
	cout << aTruck << endl << endl;
}

void moveAndUnload(Truck& aTruck, const char* destination)
{
	//cout << aTruck << endl;
	aTruck.moveTo(destination);
	if (aTruck.unloadCargo())
		cout << "Cargo unloaded!\n";
	else
		cout << "Unloading cargo failed!\n";
	cout << aTruck << endl << endl;
}

int main()
{
	{
		printHeader("T1: Vehicle");

		MotorVehicle aVehicle("VVV-111", 2010);
		cout << aVehicle << endl << endl;

		aVehicle.moveTo("Downtown Toronto");
		aVehicle.moveTo("Mississauga");
		aVehicle.moveTo("North York");

		cout << endl << aVehicle << endl << endl;

		printHeader("T2: Read/Write");
		cin >> aVehicle;
		cout << endl << aVehicle << endl << endl;
	}

	{
		printHeader("T3: Truck");

		Truck aTruck("T-1111", 2015, 5432, "Toronto HQ");
		cout << endl;

		moveAndLoad(aTruck, "Toronto Deposit", 2345);

		moveAndLoad(aTruck, "Montreal", 3456);

		moveAndLoad(aTruck, "New York", 4567);

		moveAndUnload(aTruck, "New Jersey");

		moveAndUnload(aTruck, "Toronto");


		printHeader("T4: Read/Write");
		cin >> aTruck;
		cout << endl << (MotorVehicle)aTruck;
		cout << endl << aTruck << endl << endl;
	}
}
