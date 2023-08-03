//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 06/06/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.
#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H

#include "Food.h"

namespace sdds
{
    class CalorieList
    {
        Food* m_food;
        int m_capacity;
        int m_cntFood;

        int getTotalCalories()const;
        void displayHeader() const;
        void displayFooter() const;
        bool isValid() const;

    public:

        void init(int capacity);
        bool add(const char* name, int calories, int when);
        void display()const;
        void reset();
    };


}
#endif
















