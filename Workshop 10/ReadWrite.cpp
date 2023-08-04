///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        return c.display(os);
    }

    istream& operator >> (istream& is, ReadWrite& c) {
        return c.read(is);
    }
}