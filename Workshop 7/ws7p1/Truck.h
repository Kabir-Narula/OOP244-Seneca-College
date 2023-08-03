//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 11/07/2023(Tuesday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {
		double m_capacity = 0;
		double m_load = 0;
	public:
		Truck(const char plate[], const int year, const double capacity, const char address[]);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	std::ostream& operator<<(std::ostream& os, const Truck& Ro);
	std::istream& operator>>(std::istream& is, Truck& Ro);
}

#endif