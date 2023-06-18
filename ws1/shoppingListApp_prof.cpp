/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1 Part1
// Version 1.1
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

// Cheching if header guards exist and follow convention.
#ifndef SDDS_FILE_H
	#error "The header guard for 'File.h' doesn't follow the convention!"
#endif

#ifndef SDDS_SHOPPINGLIST_H
	#error "The header guard for 'ShoppingList.h' doesn't follow the convention!"
#endif

#ifndef SDDS_UTILS_H
	#error "The header guard for 'Utils.h' doesn't follow the convention!"
#endif

int listMenu()
{
	cout << "-->>> My Shopping List <<<--" << endl;
	sdds::displayList();
	cout << "----------------------------" << endl
		 << "1- Toggle bought Item" << endl
         << "2- Add Shopping Item" << endl
         << "3- Remove Shopping Item" << endl
         << "4- Remove bought Items" << endl
         << "5- Clear List" << endl
         << "0- Exit" << endl << "> ";
	return sdds::readInt(0, 5);
}

int main()
{
	bool done = false;
	sdds::loadList();
	while (!done)
	{
		switch (listMenu())
		{
		case 1:
			sdds::toggleBought();
			break;
		case 2:
			sdds::addItemToList();
			break;
		case 3:
			removeItemfromList();
			break;
		case 4:
			sdds::removeBoughtItems();
			break;
		case 5:
			sdds::clearList();
			break;
		default:
			done = true;
			break;
		}
	}
	sdds::saveList();
	return 0;
}
