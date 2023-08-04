// Author         : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================

// Note: The following code is my own work. However, I have utilized code snippets provided by my professor in completing workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h" // Include the header file for the Car class
using namespace std;
using namespace sdds; // Use the sdds namespace since Car class is defined in that namespace

// Constructor to initialize the Car object with plate and makeModel
Car::Car(const char* plate, const char* makeModel) {
    set(plate, makeModel); // Call the set function to initialize the Car object
}

// Function to set the plate and makeModel of the Car
void Car::set(const char* plate, const char* makeModel) {
    // Copy the plate and makeModel strings using strncpy to ensure null-termination
    strncpy(m_plate, plate, 8);
    m_plate[8] = '\0';

    strncpy(m_makeModel, makeModel, 40);
    m_makeModel[40] = '\0';
}

// Function to display the Car object information
std::ostream& Car::display(std::ostream& os) const {
    // Output the plate and makeModel
    return os << m_plate << " " << m_makeModel;
}

// Function to read Car object information from user input
std::istream& Car::read(std::istream& is) {
    // Read plate and makeModel from user input
    is >> m_plate;
    is.ignore(1000, '\n'); // Ignore the remaining characters in the input buffer
    is.getline(m_makeModel, 40, '\n'); // Read makeModel with spaces if any

    return is;
}

// Function to check if the Car's makeModel contains a specific substring
bool Car::operator==(const char* mmSubstr) const {
    // Use strstr to find the substring in the makeModel
    return strstr(m_makeModel, mmSubstr) != nullptr;
}
