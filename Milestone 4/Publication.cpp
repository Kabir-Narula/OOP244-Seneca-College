/* Citation and Sources...
Final Project Milestone 4
Module: Publication.cpp
Filename: Publication.cpp
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
#include <cstring>
#include <string> 
#include <iomanip>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"

using namespace std;

namespace sdds
{
    Publication::Publication() : m_date()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
    }

    void Publication::set(int member_id) //virtual function
    {
        m_membership = (member_id > 9999 || member_id == 99999) ? member_id : 0;
    }

    void Publication::setRef(int value)
    {
        m_libRef = (value < 0) ? 0 : value;
    }

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const // virtual function 
    {
        return 'P';
    }

    bool Publication::onLoan()const
    {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    //BOOL CONVERSION
    bool Publication::operator ==(const char* title)const
    {
        return (strstr(m_title, title) != nullptr);
    }

    Publication::operator const char* () const
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(ios& ios) const
    {
        return (&ios == &cin || &ios == &cout);
    }

    ostream& Publication::write(ostream& os) const
    {
        char oldFill = os.fill();
        if (conIO(os))
        {
            os.setf(ios::left);
            os.fill('.');

            os << "| ";
            os.width(SDDS_SHELF_ID_LEN);
            os << m_shelfId;

            os << " | ";

            if (strlen(m_title) > SDDS_TITLE_WIDTH) {
                os << string(m_title, m_title + SDDS_TITLE_WIDTH);
            }
            else {
                os.width(SDDS_TITLE_WIDTH);
                os << m_title;
            }
            os << " | ";

            if (m_membership != 0)
                os << m_membership;
            else
                os << " N/A ";

            os << " | ";

            if (!m_date.errCode())
                os << m_date;
            else
                os << " N/A ";

            os << " |";

            os.fill(oldFill);
            os.unsetf(ios::left);

            return os;
        }
        else
        {
            os << type() << "\t";
            os << m_libRef;
            os << "\t";
            os << m_shelfId;
            os << "\t";
            os << m_title;
            os << "\t";
            os << m_membership;
            os << "\t";
            os << m_date;

            return os;
        }
    }

    istream& Publication::read(istream& istr)
    {
        char title[256]{};
        char shelfId[SDDS_SHELF_ID_LEN + 1]{};
        Date date;
        int libRef = -1;
        int membership = 0;

        // Deallocate any memory used by m_title
        delete[] m_title;
        m_title = nullptr;

        if (conIO(istr))
        {
            cout << "Shelf No: "; // Read the shelfID
            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');

            if (strlen(shelfId) != SDDS_SHELF_ID_LEN) // Check if shelfID is the right length
            {
                istr.setstate(ios::failbit);
            }

            cout << "Title: "; // Read the title
            istr.getline(title, 256 + 1, '\n');

            cout << "Date: "; // Read the date
            istr >> date;
        }
        else
        {
            istr >> libRef; // Read the libref
            istr.ignore();

            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t'); // Read the shelfID
            istr.getline(title, 256 + 1, '\t');  // Read the title
            istr >> membership; // Read the membership
            istr.ignore();

            // Get the date
            istr >> date;
        }

        if (!date)
        {
            istr.setstate(std::ios::failbit);
        }

        if (istr)
        {
            delete[] m_title;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            set(membership);
            m_date = date;
            setRef(libRef);
        }
        return istr;
    }

    Publication::operator bool() const
    {
        return (m_title != nullptr && m_shelfId[0] != '\0');
    }

    Publication::Publication(const Publication& source)
    {
        m_title = nullptr;
        *this = source;
    }

    Publication& Publication::operator = (const Publication& source)
    {
        if (this != &source)
        {
            m_membership = source.m_membership;
            m_libRef = source.m_libRef;
            m_date = source.m_date;
            strncpy(m_shelfId, source.m_shelfId, SDDS_SHELF_ID_LEN);
            m_shelfId[4] = '\0';

            delete[] m_title;
            if (source.m_title != nullptr && source.m_title[0] != '\0')
            {
                m_title = new char[strlen(source.m_title) + 1];
                strcpy(m_title, source.m_title);
            }
            else
                m_title = nullptr;
        }
        return *this;
    }

    Publication::~Publication()
    {
        delete[] m_title;
    }
}
