/* Citation and Sources...
Final Project Milestone 2
Module: Menu.h
Filename: Menu.h
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


#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds
{
    static const unsigned int MAX_MENU_ITEMS = 20;

    class MenuItem
    {
        char* m_menuItem;
        friend class Menu; 
        MenuItem(const char* menu = nullptr);

        // Rule of three
        MenuItem(const MenuItem& that) = delete;
        MenuItem& operator=(const MenuItem& that) = delete;
        ~MenuItem();

        operator bool() const;
        operator const char* () const;
        std::ostream& displayMenuItem(std::ostream& o) const;
    };

    class Menu
    {
        MenuItem m_title;
        MenuItem* m_item[MAX_MENU_ITEMS];
        unsigned int m_track;

    public:
        Menu(const char* title = nullptr);

        // Rule of three
        Menu(const Menu& that) = delete;
        Menu& operator=(const Menu& that) = delete;
        ~Menu();

        std::ostream& viewTitle(std::ostream& os) const;
        std::ostream& viewMenu(std::ostream& os) const;
        unsigned int run();
        unsigned int operator~();
        Menu& operator<<(const char* menuItemContent);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        friend std::ostream& operator<<(std::ostream& o, const Menu& menu);
        const char* operator[](unsigned index) const;
    };

    std::ostream& operator<<(std::ostream& o, const Menu& menu);

} // namespace sdds

#endif
