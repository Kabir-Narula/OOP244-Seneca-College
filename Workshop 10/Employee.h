///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
// Note: The following code is my own work. However, I have utilized code snippets provided by my professor in completing workshops and assignments.

#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#include "ReadWrite.h"

namespace sdds {
    class Employee : public ReadWrite {
        int m_empno; // Employee number
        int m_office; // Office number
        char m_name[41]; // Name of the employee
        double m_salary; // Salary of the employee

    public:
        // Default constructor
        Employee();

        // Constructor with parameters to initialize the employee
        Employee(int empno, const char* name, double salary, int office);

        // Function to set the employee's information
        void set(int empno, const char* name, double salary, int office);

        // Function to display employee information
        std::ostream& display(std::ostream& os) const;

        // Function to read employee information from user input
        std::istream& read(std::istream& is);

        // Function to check if the employee's office number is equal to a specific value
        bool operator==(int office) const;
    };
}
#endif // !SDDS_EMPLOYEE_H_
