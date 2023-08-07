/* Citation and Sources...
Final Project Milestone 5
Module: Menu.cpp
Filename: Menu.cpp
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/21/07  Preliminary release
2023/22/07  Debugged DMA
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
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"

namespace sdds
{
    // MenuItem Implementation

    // Default constructor for MenuItem, initializes m_content to nullptr
    MenuItem::MenuItem() : m_content(nullptr) {}

    // Custom constructor for MenuItem, sets m_content to a copy of the given itemContent
    MenuItem::MenuItem(const char* itemContent)
    {
        if (itemContent)
        {
            m_content = new char[strlen(itemContent) + 1];
            strcpy(m_content, itemContent);
        }
        else
        {
            m_content = nullptr;
        }
    }

    // Conversion operator to bool, returns true if the MenuItem has content, false otherwise
    MenuItem::operator bool() const
    {
        if (m_content != nullptr && m_content[0] != '\0')
        {
            return true;
        }
        return false;
    }

    // Conversion operator to const char*, returns the content of the MenuItem
    MenuItem::operator const char* () const
    {
        return m_content;
    }

    // MenuItem Destructor, deallocates the memory for m_content
    MenuItem::~MenuItem()
    {
        delete[] m_content;
        m_content = nullptr; // safe state
    }

    // Overloaded insertion operator to display the content of MenuItem
    std::ostream& operator<<(std::ostream& os, const MenuItem& menuItem)
    {
        if (menuItem.m_content)
        {
            os << menuItem.m_content;
        }
        return os;
    }

    // Menu Implementation

    // Default constructor for Menu, initializes m_title to nullptr and numItems to 0
    Menu::Menu()
    {
        m_title = nullptr;
        numItems = 0;
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            m_item[i] = nullptr;
        }
    }

    // Custom constructor for Menu, sets the m_title and initializes numItems to 0
    Menu::Menu(const char* menuTitle) : numItems(0)
    {
        if (menuTitle != nullptr && menuTitle[0] != '\0')
        {
            m_title = new char[strlen(menuTitle) + 1];
            strcpy(m_title, menuTitle);
        }
        else
        {
            m_title = nullptr;
        }
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            m_item[i] = nullptr;
        }
    }

    // Menu Destructor, deallocates the memory for m_title and all MenuItems
    Menu::~Menu()
    {
        delete[] m_title;
        m_title = nullptr;
        for (unsigned int i = 0; i < numItems; i++)
        {
            delete m_item[i];
        }
    }

    // Function to display the menu title
    void Menu::displayTitle() const
    {
        if (m_title != nullptr && m_title[0] != '\0')
        {
            cout << m_title << std::endl;
        }
    }

    // Function to display the entire menu
    void Menu::displayMenu() const
    {
        if (m_title != nullptr && m_title[0] != '\0')
        {
            displayTitle();
            for (unsigned int i = 0; i < numItems; i++)
            {
                cout << " " << i + 1 << "- " << m_item[i]->m_content << std::endl;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
        else
        {
            for (unsigned int i = 0; i < numItems; i++)
            {
                cout << " " << i + 1 << "- " << m_item[i]->m_content << std::endl;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
    }

    // Function to run the menu and get user selection
    unsigned int Menu::run()
    {
        displayMenu();
        unsigned int selection;
        int flag = 0;
        while (flag == 0)
        {
            if (!(cin >> selection && selection >= 0 && selection <= numItems))
            {
                cout << "Invalid Selection, try again: ";
            }
            else
                flag = 1;

            cin.clear();
            cin.ignore(1000, '\n');
        }
        return selection;
    }

    // Overloaded bitwise NOT operator to run the menu and get user selection
    unsigned int Menu::operator~()
    {
        displayMenu();
        unsigned int selection;
        cin >> selection;

        while (selection < 0 || selection > numItems)
        {
            if (!(cin >> selection && selection >= 0 && selection <= 0))
            {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        return selection;
    }

    // Overloaded left-shift operator to add a new MenuItem to the menu
    Menu& Menu::operator<<(const char* menuItemContent)
    {
        if (numItems < MAX_MENU_ITEMS)
        {
            m_item[numItems] = new MenuItem(menuItemContent);
            numItems++;
        }
        return *this;
    }

    // Conversion operator to bool, returns true if the menu has items, false otherwise
    Menu::operator bool() const
    {
        if (numItems > 0)
        {
            return true;
        }
        return false;
    }

    // Conversion operator to int, returns the number of items in the menu
    Menu::operator int() const
    {
        return this->numItems;
    }

    // Conversion operator to unsigned int, returns the number of items in the menu
    Menu::operator unsigned int() const
    {
        return this->numItems;
    }

    // Overloaded insertion operator to display the menu title
    std::ostream& operator<<(std::ostream& os, const Menu& menu)
    {
        if (menu.m_title)
        {
            os << menu.m_title;
        }
        return os;
    }

    // Overloaded subscript operator to get the content of a MenuItem at a specific index
    const char* Menu::operator[](unsigned int index) const
    {
        if (*this)
        {
            if (index > this->numItems)
            {
                return this->m_item[index % numItems]->operator const char* ();
            }
            else
            {
                return this->m_item[index]->operator const char* ();
            }
        }
        // Return a default value in case the above conditions are not met
        return nullptr;
    }
}
