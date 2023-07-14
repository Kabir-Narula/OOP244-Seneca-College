//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 11/07/2023(Tuesday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.




#include <iostream>
#include <cstring>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	MotorVehicle::MotorVehicle(const char plate[], const int year) {
		strCpy(m_plate, plate);
		strCpy(m_address, "Factory");
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		cout << '|';
		cout.width(8);
		cout << m_plate;
		cout << "| |";

		cout.width(20);
		cout << m_address;

		cout << " ---> ";

		cout.width(20);
		cout.setf(ios::left);
		if (strCmp(m_address, address))
			strCpy(m_address, address);
		cout << m_address;
		cout.unsetf(ios::left);

		cout << '|' << endl;
	}

	ostream& MotorVehicle::write(ostream& os)const {
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;
	}

	istream& MotorVehicle::read(istream& is) {
		cout << "Built year: ";
		is >> m_year;

		cout << "License plate: ";
		is >> m_plate;

		cout << "Current location: ";
		is >> m_address;

		return is;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& Ro) {
		return Ro.write(os);
	}

	istream& operator>>(istream& is, MotorVehicle& Ro) {
		return Ro.read(is);
	}
}
