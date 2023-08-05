/* Citation and Sources...
Final Project Milestone 1
Module: Menu.cpp
Filename: Menu.cpp
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/07  Preliminary release
2023/12/07  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include <iomanip>

namespace sdds {
    // MenuItem class implementation
    MenuItem::MenuItem() {
        m_menuItem = nullptr;
    }

    MenuItem::MenuItem(const char* item) {
        m_menuItem = new char[strlen(item) + 1];
        strcpy(m_menuItem, item);
    }

    MenuItem::~MenuItem() {
        delete[] m_menuItem;
    }

    MenuItem::operator bool() const {
        return (m_menuItem != nullptr);
    }

    void MenuItem::display() {
        std::cout << m_menuItem;
    }

    // Menu class implementation
    Menu::Menu() {
        m_menuTitle = nullptr;
        m_noofmenu = 0;
    }

    Menu::Menu(const char* title) {
        m_menuTitle = new char[strlen(title) + 1];
        strcpy(m_menuTitle, title);
        m_noofmenu = 0;
    }

    Menu::~Menu() {
        delete[] m_menuTitle;
        for (int i = 0; i < m_noofmenu; i++) {
            delete m_items[i];
        }
    }

    int Menu::run() {
        display();
        int selection;
        std::cin >> selection;
        while (std::cin.fail() || selection < 0 || selection > m_noofmenu) {
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cout << "Invalid Selection, try again: ";
            std::cin >> selection;
        }
        return selection;
    }

    char* Menu::operator[](int i) const {
        return m_items[i]->m_menuItem;
    }

    Menu::operator bool() const {
        return (m_menuTitle != nullptr);
    }

    int Menu::operator~() {
        display();
        int selection;
        std::cin >> selection;
        while (selection < 0 || selection > m_noofmenu) {
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cout << "Invalid Selection, try again: ";
            std::cin >> selection;
        }
        return selection;
    }

    void Menu::display() {
        if (m_menuTitle != nullptr) {
            std::cout << m_menuTitle << ":\n";
        }
        for (int i = 0; i < m_noofmenu; i++) {
            std::cout << " " << i + 1 << "- " << m_items[i]->m_menuItem << std::endl;
        }
        std::cout << " 0- Exit\n> ";
    }

    std::ostream& Menu::write(std::ostream& os) const {
        if (m_menuTitle != nullptr) {
            os << m_menuTitle;
        }
        return os;
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        m_items[m_noofmenu++] = new MenuItem(menuitemContent);
        return *this;
    }

    Menu::operator unsigned int() const {
        return m_noofmenu;
    }

    std::ostream& operator<<(std::ostream& os, const Menu& m) {
        return m.write(os);
    }
}
