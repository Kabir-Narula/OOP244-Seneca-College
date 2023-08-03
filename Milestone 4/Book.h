/* Citation and Sources...
Final Project Milestone 4
Module: Book.h
Filename: Book.h
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


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"
#include "Streamable.h"

namespace sdds {

    class Book : public Publication {

        char* m_author;

    public:
        Book();

        Book(const Book& src);

        Book& operator=(const Book& src);

        ~Book();

        char type()const;

        std::ostream& write(std::ostream& os) const;

        std::istream& read(std::istream& istr);

        void set(int member_id);

        operator bool() const;


    };
}


#endif