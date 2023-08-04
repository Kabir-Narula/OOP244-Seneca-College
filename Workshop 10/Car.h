///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
// Note: The following code is my own work. However, I have utilized code snippets provided by my professor in completing workshops and assignments.

#include <iostream>
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include "ReadWrite.h"

namespace sdds {
    class Car : public ReadWrite {
        char m_plate[9]; // License plate number of the car
        char m_makeModel[41]; // Make and model of the car

    public:
        // Constructor with optional parameters to initialize the car's plate and makeModel
        Car(const char* plate = "", const char* makeModel = "");

        // Function to set the car's plate and makeModel
        void set(const char* plate, const char* makeModel);

        // Function to display car information
        std::ostream& display(std::ostream& os) const;

        // Function to read car information from user input
        std::istream& read(std::istream& is);

        // Function to check if the car's makeModel contains a specific substring
        bool operator==(const char* mmSubstr) const;
    };
}
#endif // !SDDS_CAR_H_
