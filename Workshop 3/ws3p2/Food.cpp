//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 06/06/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  
#include "Food.h"

using namespace std;

namespace sdds
{
    //global constant integeres are used to represent the meal time

    const int g_breakfast = 1;
    const int g_lunch = 2;
    const int g_dinner = 3;
    const int g_snack = 4;



    void Food::init()
    {

        m_name[0] = '\0';

        m_calories = 0;

        m_when = 0;

    }





    bool Food::set(const char* name, int calories, int when)
    {


        bool ok = false;

        if (name == nullptr || name[0] == '\0'
            || (calories < MIN_CALS || calories > MAX_CALS) ||
            (when <  g_breakfast || when > g_snack))
        {
            init(); // called if arguments are invalid. Will set object to empty state. 
        }
        else
        {
            ok = true;
            //initializing the passed arguments to the attributes
            strncpy(m_name, name, FOOD_NAME);
            m_name[FOOD_NAME] = '\0';
            m_calories = calories;
            m_when = when;
        }

        return ok;
    }



    void Food::display()const
    {
        char currentFill = cout.fill();


        const char* mealTime = getMeal(m_when);

        if (isEmpty() == false)
        {
            cout << "| ";
            cout.width(FOOD_NAME);
            cout.setf(ios::left);
            cout.fill('.');

            cout << m_name;

            cout << " | ";
            cout.width(CALORIES);
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout.fill(' ');


            cout << m_calories;

            cout << " | ";
            cout.width(WHEN);
            cout.unsetf(ios::right);
            cout.setf(ios::left);

            cout << mealTime;
            cout << " |";
        }
        else
        {
            cout << "| ";
            cout.width(FOOD_NAME);
            cout.setf(ios::left);
            cout.fill('x');

            cout << "xxx";

            cout << " | ";
            cout.width(CALORIES);
            cout.unsetf(ios::left);
            cout.setf(ios::right);

            cout << "xxx";

            cout << " | ";
            cout.width(WHEN);
            cout.unsetf(ios::right);
            cout.setf(ios::left);

            cout << "xxx";
            cout << " |";
        }
        cout << "\n";

        cout.unsetf(ios::left);
        cout.unsetf(ios::right);

        cout.fill(currentFill);
    }

    bool Food::isEmpty()const
    {
        if (m_name[0] == '\0')
            return true;
        else
            return false;
    }

    int Food::getCalories()const
    {
        return m_calories;
    }

    const char* Food::getMeal(int when)const
    {


        if (when == g_breakfast)
        {
            return "Breakfast";
        }
        else if (when == g_lunch)
        {
            return  "Lunch";
        }
        else if (when == g_dinner)
        {
            return "Dinner";
        }
        else if (when == g_snack)
        {
            return "Snack";
        }
        return "invalid";
    }
}














