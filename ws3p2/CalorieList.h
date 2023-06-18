
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
















