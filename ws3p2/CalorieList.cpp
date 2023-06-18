
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring> 
#include "CalorieList.h"
#include "Food.h"

using namespace std;

namespace sdds
{
    int CalorieList::getTotalCalories() const
    {
        int totalCals = 0;

        for (int i = 0; i < m_cntFood; i++)
        {
            totalCals += m_food[i].getCalories();
        }
        return totalCals;
    }

    void CalorieList::displayHeader()const
    {
        char currentFill = cout.fill();

        cout << "+----------------------------------------------------+" << endl;
        cout << "| ";
        cout.width(FOOD_NAME + CALORIES + WHEN + 6);
        cout.setf(ios::left);
        cout.fill(' ');

        if (isValid() == true)
            cout << " Daily Calorie Consumption";
        else
            cout << "Invalid Calorie Consumption list";

        cout << " |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;

        cout << "| ";
        cout.width(FOOD_NAME);
        cout.setf(ios::left);

        cout << "Food name";

        cout << " | ";
        //following the space after the above cout, the next changes will occur. 
        cout.width(CALORIES);
        cout.unsetf(ios::left);//must unset previous setf() and then apply the next change 
        cout.setf(ios::right); //change made here. will print from the right. 

        cout << "Cals";

        cout << " | ";
        cout.width(WHEN);
        cout.unsetf(ios::right);
        cout.setf(ios::left);

        cout << "When";
        cout << " |" << endl;

        cout << "+--------------------------------+------+------------+" << endl;

        cout.unsetf(ios::right);
        cout.unsetf(ios::left);
        cout.fill(currentFill);
    }

    void CalorieList::displayFooter() const
    {
        int precision = cout.precision();
        char currentFill = cout.fill();
        int totalCals = getTotalCalories();

        cout << "+--------------------------------+------+------------+" << endl;
        cout.fill(' ');
        cout.width(CALORIES + 1);
        cout.setf(ios::left);
        cout << "|";

        if (isValid() == false)
        {
            cout.width(FOOD_NAME + 1 + WHEN + 7);
            cout.setf(ios::left);
            cout << "Invalid Calorie Consumption list";
            cout.setf(ios::right);
            cout << "|";
            cout << "\n";
        }
        else
        {
            cout.width(FOOD_NAME);
            cout << "Total Calories for today:";

            cout.width(CALORIES + 1);
            cout.setf(ios::left);
            cout.precision(2);
            cout << totalCals;
            cout << "|";

            cout.width(WHEN + 3);
            cout.setf(ios::right);
            cout << "|";
            cout << "\n";
        }

        cout.fill(currentFill);
        cout.unsetf(ios::right);
        cout.unsetf(ios::left);
        cout.precision(precision);

        cout << "+----------------------------------------------------+" << endl;

    }

    bool CalorieList::isValid()const
    {
        //function will check if object has valid data. 
        int i;
        int flag = 0;
        // iterares over array of objects to see if there is an empty string
        for (i = 0; i < m_capacity; i++)
        {
            if (m_food[i].isEmpty())
                flag = 1;
        }

        if (m_food != nullptr && flag == 0)
            return true;
        else
            return false;
    }

    void CalorieList::init(int capacity)
    {
        /// <summary>
        /// Initializes the list to be able to store `capacity` objects of type `Food`.
        /// </summary>
        /// <param name="capacity">An integer representing the maximum number of
        ///   items this list can accommodate.
        /// 
        ///   **Valid capacity**: any number bigger than 0.</param>
        if (capacity > 0)
        {
            m_food = new Food[capacity]; //allocates memory with the size of "capacity"
            m_capacity = capacity;

            //loop will iterate over m_food array and initialize it to an empty state. 
            for (int i = 0; i < capacity; i++)
            {
                m_food[i].init();
            }
            m_cntFood = 0;
        }
        else
        {
            m_food = nullptr;
            m_capacity = 0;
            m_cntFood = 0;
        }
    }

    bool CalorieList::add(const char* name, int calories, int when)
    {
        /// <summary>
        /// Add a new food to the list, if there is capacity.
        /// </summary>
        /// <param name="food_name">A C-string containing the name of the food item.</param>
        /// <param name="calories">An integer storing how many calories the food has.</param>
        /// <param name="when">An integer representing when this food will be consumed.</param>
        /// <returns>`true` if the food has been added to the list, `false` otherwise.</returns>
        bool ok = false;

        if (m_cntFood < m_capacity)
        {
            ok = m_food[m_cntFood].set(name, calories, when);
            m_cntFood++;
        }
        return ok;
    }

    void CalorieList::display()const
    {
        /// <summary>
        /// Prints to screen the content of the list.  Look in the sample output
        ///   for hints about formatting.
        /// </summary>
        displayHeader();

        for (int i = 0; i < m_capacity; i++)
        {
            m_food[i].display();
        }

        displayFooter();
    }

    void CalorieList::reset()
    {
        /// <summary>
        /// Deallocates all dynamic memory used by this object and sets all attributes to
        ///   a default value.
        /// </summary>

        delete[] m_food;

        m_capacity = 0;
        m_cntFood = 0;
    }


}





































