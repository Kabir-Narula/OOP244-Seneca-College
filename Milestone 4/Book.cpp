/* Citation and Sources...
Final Project Milestone 4
Module: Book.cpp
Filename: Book.cpp
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"
#include "Lib.h"

using namespace std;

namespace sdds {

    Book::Book() : m_author(nullptr) {}

    Book::Book(const Book& src) : m_author(nullptr) {
        *this = src;
    }

    Book& Book::operator=(const Book& src) {
        if (this != &src) {
            Publication::operator=(src);
            delete[] m_author;
            if (src.m_author != nullptr) {
                m_author = new char[strlen(src.m_author) + 1];
                strcpy(m_author, src.m_author);
            }
            else {
                m_author = nullptr;
            }
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_author;
        m_author = nullptr;
    }

    char Book::type() const {
        return 'B';
    }

    ostream& Book::write(ostream& os) const {
      
        Publication::write(os);

        if (Publication::conIO(os)) {

            os << ' ';

            if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {

                

                for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
                    os << m_author[i];
                }


            }
            else {
                os << setw(SDDS_AUTHOR_WIDTH) << left << m_author << right;
            }

            os << " |";

        }
        else {

            os << '\t' << m_author;

        }
        return os;
    }

    istream& Book::read(istream& istr) {
        char author[256 + 1]{};
        Publication::read(istr);
        delete[] m_author;
        if (Publication::conIO(istr)) {
            istr.ignore(3000, '\n');
            cout << "Author: ";
            istr.getline(author, 256 + 1, '\n');
        }
        else {
            istr.ignore();
            istr.get(author, 256 + 1, '\n');
        }
        if (istr) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }
        return istr;
    }

    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const {
        return Publication::operator bool() && m_author && m_author[0] != '\0';
    }

}
