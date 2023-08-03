/* Citation and Sources...
Final Project Milestone 4
Module: Streamable.cpp
Filename: Streamable.cpp
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/08  Preliminary release
2023/02/08  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream> 
#include "Streamable.h"

using namespace std;

namespace sdds
{
    std::ostream& operator<<(std::ostream& os, const Streamable& stream)
    {
        if (stream)
            stream.write(os);
        // else
        //     os << "a";

        return os;
    }
    std::istream& operator >> (std::istream& is, Streamable& stream)
    {
        stream.read(is);

        return is;
    }

    Streamable::~Streamable()
    {

    }
}