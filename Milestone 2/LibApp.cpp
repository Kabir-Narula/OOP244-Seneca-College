/* Citation and Sources...
Final Project Milestone 2
Module: LibApp.cpp
Filename: Libapp.cpp
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



#define _crt_secure_no_warnings
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "Utils.h"
#include "LibApp.h"
using namespace std;
namespace sdds
{
	// Function to confirm user input (yes or no)
	bool LibApp::confirmAction(const char* message)
	{
		Menu confirmationMenu(message);
		confirmationMenu << "Yes";
		unsigned int confirmationChoice = confirmationMenu.run();
		return (confirmationChoice == 1);
	}

	// Print "Loading Data" message
	void LibApp::loadData()
	{
		cout << "Loading Data" << endl;
	}

	// Print "Saving Data" message
	void LibApp::saveData()
	{
		cout << "Saving Data" << endl;
	}

	// Print "Searching for publication" message
	void LibApp::searchPublication()
	{
		cout << "Searching for publication" << endl;
	}

	// Return a publication to the library
	void LibApp::returnPublicationtolibrary()
	{
		searchPublication();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
		cout << endl;
	}

	// Add a new publication to the library
	void LibApp::addNewPublicationtolibrary()
	{
		cout << "Adding new publication to library" << endl;

		if (confirmAction("Add this publication to library?"))
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;
	}

	// Remove a publication from the library
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		searchPublication();

		if (confirmAction("Remove this publication from the library?"))
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;
	}

	// Checkout a publication from the library
	void LibApp::checkoutPublication()
	{
		searchPublication();
		if (confirmAction("Check out publication?"))
		{
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}

	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		loadData();
	}

	void LibApp::run()
	{
		bool done = true;

		while (done)
		{
			
			int choice = m_mainMenu.run();
			
			switch (choice)
			{
			case 1:
				addNewPublicationtolibrary();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkoutPublication();
				break;
			case 4:
				returnPublicationtolibrary();
				break;
			case 0:
				
				if (m_changed)
				{
					
					unsigned int exitChoice = m_exitMenu.run();
					if (exitChoice == 1)
					{
						saveData();
						done = false;
					}
					else if (exitChoice == 2)
					{
						cout << endl;
					}
					else
					{
						int confirmed = confirmAction("This will discard all the changes are you sure?");
						if (confirmed == 1)
						{
							done = false;
						}
						else
						{
							cout << endl;
						}
					}
				}
				else
				{
					// No changes made, exit program
					done = false;
				}
				break;
			default:
				cout << "Invalid selection. Please try again." << endl;
				break;
			}
		}

		// Print termination message
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}
