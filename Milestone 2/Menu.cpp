/* Citation and Sources...
Final Project Milestone 2
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



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

// MenuItem Implementation
MenuItem::MenuItem(const char* menu)
{
	if (menu != nullptr && menu[0] != '\0')
	{
		m_menuItem = new char[strlen(menu) + 1];
		strcpy(m_menuItem, menu);
	}
	else
	{
		m_menuItem = nullptr;
	}
}

MenuItem::~MenuItem()
{
	delete[] m_menuItem;
}

MenuItem::operator bool() const
{
	return (m_menuItem != nullptr);
}

MenuItem::operator const char* () const
{
	return m_menuItem;
}

ostream& MenuItem::displayMenuItem(ostream& o) const
{
	if (m_menuItem)
	{
		o << m_menuItem;
	}
	return o;
}

// Menu Class Implementation
Menu::Menu(const char* title) : m_title(title), m_track(0)
{
	// Constructor
}

Menu::~Menu()
{
	// Destructor
	for (unsigned i = 0; i < m_track; ++i)
	{
		delete m_item[i];
	}
}

ostream& Menu::viewTitle(ostream& os) const
{
	if (m_title)
	{
		m_title.displayMenuItem(os);
	}
	return os;
}

ostream& Menu::viewMenu(ostream& os) const
{
	if (m_title)
	{
		viewTitle(os);
		os << endl;
	}

	for (unsigned int i = 0; i < m_track; i++)
	{
		os.width(2);
		os.setf(ios::right);
		os << i + 1 << "- ";
		(*m_item[i]).displayMenuItem(os);
		os.unsetf(ios::right);
		os << endl;
	}
	cout << " 0- Exit" << endl;
	cout << "> ";

	return os;
}

unsigned int Menu::run()
{
	unsigned int choice;
	int validChoice = 0;
	viewMenu(cout);

	do
	{
		if (cin >> choice && choice >= 0 && choice <= m_track)
		{
			validChoice = 1;
		}
		else
		{
			cout << "Invalid Selection, try again: ";
		}
		cin.clear();
		cin.ignore(2000, '\n');

	} while (validChoice == 0);

	return choice;
}

unsigned int Menu::operator~()
{
	return run();
}

Menu& Menu::operator<<(const char* menuItemContent)
{
	if (menuItemContent != nullptr && menuItemContent[0] != '\0' && m_track < MAX_MENU_ITEMS)
	{
		m_item[m_track] = new MenuItem(menuItemContent);
		m_track++;
	}

	return *this;
}

Menu::operator int() const
{
	return m_track;
}

Menu::operator unsigned int() const
{
	return m_track;
}

Menu::operator bool() const
{
	return (m_track > 0);
}

ostream& operator<<(ostream& o, const Menu& menu)
{
	menu.viewTitle(o);
	return o;
}

const char* Menu::operator[](unsigned int index) const
{
	if (*this)
	{
		if (index > m_track)
		{
			return m_item[index % m_track]->operator const char* ();
		}
		else
		{
			return m_item[index]->operator const char* ();
		}
	}
	return nullptr;
}
