/* Citation and Sources...
Final Project Milestone 1
Module: Menu.cpp
Filename: Menu.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/07  Preliminary release
2023/12/07  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include <iomanip>
using namespace std;

namespace sdds {

    MenuItem::MenuItem()
    {
        m_menuItem = nullptr;
    }

    MenuItem::MenuItem(const char* i)
    {
        delete[] m_menuItem;
        m_menuItem = new char[strlen(i) + 1];
        strcpy(m_menuItem, i);
    }

    MenuItem::~MenuItem()
    {
        delete[] m_menuItem;
    }

    MenuItem::operator bool() const {

        if (m_menuItem != nullptr)
        {
            return true;
        }
        return false;
    }

    void MenuItem::display() {
        std::cout << m_menuItem;
    }


    Menu::Menu()
    {
        m_menuTitle = nullptr;
        m_noofmenu = 0;
    }

    Menu::Menu(const char* n)
    {
        delete[] m_menuTitle;
        m_menuTitle = new char[strlen(n) + 1];
        strcpy(m_menuTitle, n);
    }

    Menu::~Menu()
    {
        delete[] m_menuTitle;
        for (int i = 0; i < m_noofmenu; i++)
        {
            delete m_items[i];
        }
    }

    void Menu::display()
    {
        if (m_menuTitle != nullptr)
        {
            cout << m_menuTitle << ":\n";
        }
        for (int i = 0; i < m_noofmenu; i++)
        {
            cout << " " << i + 1 << "- " << m_items[i]->m_menuItem << endl;
        }
        cout << " 0- Exit\n> ";
    }

    int Menu::run()
    {
        display();
        char c;
        cin >> c;
        int x = c - '0';
        while (x  < 0 || x > m_noofmenu)
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> c;
            x = c - '0';
        }
        return x;
    }

    Menu::operator bool() const
    {
        if (m_menuTitle == nullptr)
        {
            return false;
        }
        return true;
    }

    int Menu::operator~()
    {
        display();
        char c;
        cin >> c;

        int x = c - '0';
        while (x  < 0 || x > m_noofmenu)
        {

            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> c;
            x = c - '0';
        };
        return x;
    }

    Menu& Menu::operator<<(const char* menuitemConent)
    {
        m_items[m_noofmenu++] = new MenuItem(menuitemConent);
        return *this;
    }

    Menu::operator unsigned int() const {
        return m_noofmenu;
    }

    std::ostream& Menu::write(std::ostream& o)const
    {
        if (m_menuTitle != nullptr)
        {
            o << m_menuTitle;
        }
        return o;
    }

    std::ostream& operator<<(std::ostream& o, const Menu& M)
    {
        return M.write(o);
    }

    char* Menu::operator[](int i) const
    {
        return m_items[i]->m_menuItem;
    }
}