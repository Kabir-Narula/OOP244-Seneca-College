///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
// Note: The following code is my own work. However, I have utilized code snippets provided by my professor in completing workshops and assignments.

#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#include "ReadWrite.h"

namespace sdds {
    class Student : public ReadWrite {
        int m_stno; // Student number
        char m_name[41]; // Name of the student
        double m_gpa; // Grade point average of the student

    public:
        // Default constructor
        Student();

        // Constructor with parameters to initialize the student
        Student(int stno, const char* name, double gpa);

        // Function to set the student's information
        void set(int stno, const char* name, double gpa);

        // Function to display student information
        std::ostream& display(std::ostream& os) const;

        // Function to read student information from user input
        std::istream& read(std::istream& is);

        // Function to check if the student's GPA is equal to a specific value
        bool operator==(double gpa) const;
    };
}
#endif // !SDDS_STUDENT_H_
