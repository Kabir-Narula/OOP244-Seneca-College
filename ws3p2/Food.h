
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds
{
    const int FOOD_NAME = 30;
    const int CALORIES = 4;
    const int WHEN = 10;
    const int MAX_CALS = 3000;
    const int MIN_CALS = 1;


    class Food
    {
        char m_name[FOOD_NAME + 1];

        int m_calories;

        int m_when;

    public:
        /*This function will be used to initialize values to a default / empty state.*/
        void init();

        /* set and store the values in the attributes*/
        bool set(const char* name, int calories, int when);

        void display() const;

        /* checking to see if the name attribute of a Food object is empty.*/
        bool isEmpty()const;

        int getCalories()const;

        const char* getMeal(int when)const;

    };
}


#endif








