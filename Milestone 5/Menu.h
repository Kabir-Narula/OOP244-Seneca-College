/* Citation and Sources...
Final Project Milestone 5
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

//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>

namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem;

	class MenuItem
	{
		char* m_content; //characters for the content of the menu item dynamically

		MenuItem(); //constructor
		MenuItem(const char* itemContent); //custom constructor
		operator bool() const;
		operator const char* () const;
		//ostream& display(ostream& os) const;
		~MenuItem(); //destructor
		friend class Menu;
		friend std::ostream& operator<<(std::ostream& os, const MenuItem& menuItem);
	};

	class Menu
	{
		char* m_title; //A MenuItem to possibly hold the title of the Menu.
		MenuItem* m_item[MAX_MENU_ITEMS]; //An array of MenuItem pointers.
		unsigned int numItems; //MenuItem pointers are pointing to dynamic MenuItem objects. 

	public:
		Menu(); //constructor A Menu is always created empty; with no MenuItems, with or without a title.
		Menu(const char* menuTitle);
		~Menu();

		void displayTitle() const; //display the title of the Menu on ostream if the title is not empty, otherwise, it does nothing.
		void displayMenu() const; //Create a function to display the entire Menu on ostream

		unsigned int run(); //Create a member function called run

		//Overload operator~ to do exactly what the run function does(two different ways to run the menu)
		unsigned int operator~();

		Menu& operator<<(const char* menuItemContent); //Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.

		operator bool() const;
		operator int() const;
		operator unsigned int() const;

		friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
		const char* operator[](unsigned int index) const;
	};

}
#endif
