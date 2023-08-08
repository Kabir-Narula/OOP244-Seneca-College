/* Citation and Sources...
Final Project Milestone 3
Module: Publication.h
Filename: Publication.h
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


#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream> 
#include "Date.h"
#include "Streamable.h"

namespace sdds
{
    class Publication : public Streamable
    {
        char* m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;
        bool conIO(std::ios& ios) const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        operator bool() const;
        Publication(const Publication& pub);
        Publication& operator=(const Publication& pub);
        ~Publication();
    };
}

#endif
