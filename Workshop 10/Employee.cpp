///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Employee.h"
namespace sdds {
    Employee::Employee() {
        set(0, "", 0.0, 0);
    }
    Employee::Employee(int stno, const char* name, double salary, int office) {
        set(stno, name, salary, office);
    }
    void Employee::set(int stno, const char* name, double salary, int office) {
        m_empno = stno;
        strcpy(m_name, name);
        m_salary = salary;
        m_office = office;
    }
    ostream& Employee::display(ostream& os)const {
        return os << m_empno << " " << m_name << " (Office# " << m_office << ") Salary: $" << setprecision(2) << fixed << m_salary;
    }
    istream& Employee::read(istream& is) {
        is >> m_empno;
        is.getline(m_name, 40, ',');
        is >> m_salary;
        return is;
    }
    bool Employee::operator==(int office)const {
        return m_office == office;
    }
}