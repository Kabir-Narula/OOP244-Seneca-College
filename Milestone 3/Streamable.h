/* Citation and Sources...
Final Project Milestone 3
Module: Streamable.h
Filename: Streamable.h
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/27/07  Preliminary release
2023/27/07  Debugged DMA
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
#ifndef SDDS_ISTREAMABLE_H
#define SDDS_ISTREAMABLE_H
#include <iostream>

namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& ios) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
        friend std::ostream& operator<<(std::ostream& os, const Streamable& stream);
        friend std::istream& operator >> (std::istream& is, Streamable& stream);

    };
}

#endif