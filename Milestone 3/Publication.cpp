/* Citation and Sources...
Final Project Milestone 3
Module: Publication.cpp
Filename: Publication.cpp
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

#define _CRT_SECURE_NO_WARNINGS
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

    void Publication::set(int member_id)
    {
        if (member_id > 9999 || member_id == 99999)
            m_membership = member_id;
        else
            m_membership = 0;
    }

    void Publication::setRef(int value)
    {
        if (value < 0)
            m_libRef = 0;
        else
            m_libRef = value;
    }

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char* title) const
    {
        if (strstr(m_title, title))
            return true;
        else
            return false;
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
        if (&ios == &cin || &ios == &cout)
            return true;
        else
            return false;
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
            os.width(SDDS_TITLE_WIDTH);
            os << m_title;
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
        char title[SDDS_TITLE_WIDTH + 1]{};
        char shelfId[SDDS_SHELF_ID_LEN + 1]{};
        Date date;
        int libRef = -1;
        int membership = 0;

        if (m_title != nullptr)
            delete[] m_title;

        m_title = nullptr;

        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        if (conIO(istr))
        {
            cout << "Shelf No: ";
            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');

            if (strlen(shelfId) != SDDS_SHELF_ID_LEN)
            {
                istr.setstate(ios::failbit);
            }

            cout << "Title: ";
            istr.getline(title, SDDS_TITLE_WIDTH + 1);

            cout << "Date: ";
            istr >> date;
        }
        else
        {
            istr >> libRef;
            istr.ignore();

            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');

            istr.getline(title, SDDS_TITLE_WIDTH + 1, '\t');

            istr >> membership;
            istr.ignore();

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

    Publication::Publication(const Publication& pub)
    {
        m_title = nullptr;
        *this = pub;
    }

    Publication& Publication::operator=(const Publication& pub)
    {
        if (this != &pub)
        {
            m_membership = pub.m_membership;
            m_libRef = pub.m_libRef;
            m_date = pub.m_date;
            strncpy(m_shelfId, pub.m_shelfId, SDDS_SHELF_ID_LEN);
            m_shelfId[4] = '\0';

            if (m_title != nullptr)
                delete[] m_title;

            if (pub.m_title != nullptr && pub.m_title[0] != '\0')
            {
                m_title = new char[strlen(pub.m_title) + 1];
                strcpy(m_title, pub.m_title);
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
