//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 11/07/2023(Tuesday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.





#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>

namespace sdds {

	class MotorVehicle {
		char m_plate[9] = { '\0' };
		char m_address[64] = { '\0' };
		int m_year = 0;
	public:
		MotorVehicle(const char plate[], const int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& Ro);
	std::istream& operator>>(std::istream& is, MotorVehicle& Ro);
}

#endif