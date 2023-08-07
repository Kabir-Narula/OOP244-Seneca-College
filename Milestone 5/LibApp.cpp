/* Citation and Sources...
Final Project Milestone 5
Module: LibApp.cpp
Filename: LibApp.cpp
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/08  Preliminary release
2023/02/08  Debugged DMA
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Publication.h"
#include "Book.h"
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Date.h"
#include "Lib.h"
#include "Menu.h"
#include "Utils.h"
#include "Streamable.h"
using namespace std;

namespace sdds {
	
	// LibApp Constructor
	LibApp::LibApp(const char* filename)
		: m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_nolp(0),
		m_pubTypeMenu("Choose the type of publication:")
	{
		this->m_changed = false;

		if (filename)
		{
			strcpy(this->m_filename, filename);
		}

		// Setting up main menu and exit menu options
		this->m_mainMenu << "Add New Publication"
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";

		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";

		// Setting up publication type menu options
		this->m_pubTypeMenu << "Book";
		this->m_pubTypeMenu << "Publication";
		load();
	}

	// Function to display a confirmation menu and return the user's choice
	bool LibApp::confirm(const char* message)
	{
		Menu confirmMenu(message);
		confirmMenu << "Yes";

		if (confirmMenu.run() == 1)
		{
			return true;
		}
		cout << "\n";
		return false;
	}

	// Function to load data from the file into the application
	void LibApp::load()
	{
		cout << "Loading Data" << endl;

		ifstream file(this->m_filename);

		char kind;
		for (int i = 0; i < SDDS_LIBRARY_CAPACITY and file; i++)
		{
			file >> kind;
			file.ignore();

			if (file)
			{
				if (kind == 'P')
				{
					m_ppa[i] = new Publication;
				}
				else if (kind == 'B')
				{
					m_ppa[i] = new Book;
				}
				if (m_ppa[i])
				{
					file >> *m_ppa[i];
					m_nolp++;
					m_llrn = m_ppa[i]->getRef();
				}
			}
		}
	}

	// Function to save data from the application into the file
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream file(this->m_filename);

		if (!file)
		{
			cout << "Error opening file: " << m_filename << endl;
			return;
		}

		for (int i = 0; i < m_nolp; i++)
		{
			if (m_ppa[i]->getRef() != 0)
			{
				file << *m_ppa[i] << endl;
			}
		}
	}

	// Function to search for a publication based on various criteria and return the library reference number
	int LibApp::search(int mode)
	{
		PublicationSelector that("Select one of the following found matches:");
		int typechoice = m_pubTypeMenu.run();
		char s;

		if (typechoice == 2)
		{
			s = 'P';
		}
		else if (typechoice == 1)
		{
			s = 'B';
		}
		else
		{
			cout << "Aborted!" << endl;
		}

		char title[256]{};
		cout << "Publication Title: ";
		cin.getline(title, 256);

		if (mode == 1)
		{
			for (int i = 0; i < m_nolp; i++)
			{
				if (m_ppa[i]->getRef() != 0 and
					m_ppa[i]->operator==(title) and
					m_ppa[i]->type() == s)
				{
					that << m_ppa[i];
				}
			}
		}
		if (mode == 2)
		{
			for (int i = 0; i < m_nolp; i++)
			{
				if (m_ppa[i]->getRef() != 0 and
					m_ppa[i]->operator==(title) and
					m_ppa[i]->type() == s and
					m_ppa[i]->onLoan())
				{
					that << m_ppa[i];
				}
			}
		}
		if (mode == 3)
		{
			for (int i = 0; i < m_nolp; i++)
			{
				if (m_ppa[i]->getRef() != 0 and
					m_ppa[i]->operator==(title) and
					m_ppa[i]->type() == s and
					!m_ppa[i]->onLoan())
				{
					that << m_ppa[i];
				}
			}
		}

		int libref = 0;

		if (that)
		{
			that.sort();

			libref = that.run();
			if (libref > 0)
			{
				cout << *getPub(libref) << endl;
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}
		else
		{
			cout << "No matches found!" << endl;
		}
		return libref;
	}

	// Function to retrieve a publication pointer based on its library reference number
	Publication* LibApp::getPub(int libRef)
	{
		Publication* pub = nullptr;
		for (int i = 0; i < m_nolp; i++)
		{
			if (m_ppa[i]->getRef() == libRef)
			{
				pub = m_ppa[i];
			}
		}
		return pub;
	}

	// Function to return a publication to the library
	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;
		int libref = search(2);
		if (libref > 0)
		{
			if (confirm("Return Publication?"))
			{
				int day = Date() - getPub(libref)->checkoutDate();

				if (day > SDDS_MAX_LOAN_DAYS)
				{
					double penalty = (day - SDDS_MAX_LOAN_DAYS) * 0.5;
					cout << fixed << setprecision(2) << "Please pay $" << penalty << " penalty for being " << (day - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
				}

				getPub(libref)->set(0);
				m_changed = true;
			}
			cout << "Publication returned" << endl;
		}
		cout << endl;
	}

	// Function to add a new publication to the library
	void LibApp::newPublication()
	{
		bool ok = false;

		if (m_nolp == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
			ok = true;
		}

		if (!ok)
		{
			cout << "Adding new publication to the library" << endl;
			int typeChoice = m_pubTypeMenu.run();
			Publication* that = nullptr;

			if (typeChoice == 0)
			{
				cout << "Aborted!" << endl;
				ok = true;
			}
			else if (typeChoice == 1)
			{
				that = new Book;
				cin >> *that;
			}
			else if (typeChoice == 2)
			{
				that = new Publication;
				cin >> *that;
			}

			if (cin.fail())
			{
				cin.ignore(1000, '\n');
				cin.clear();
				cout << "Aborted!" << endl;
				ok = true;
			}
			else
			{
				if (!ok and confirm("Add this publication to the library?"))
				{
					if (*that)
					{
						m_llrn++;
						that->setRef(m_llrn);
						m_ppa[m_nolp] = that;
						m_nolp++;
						m_changed = true;
						cout << "Publication added" << endl;
					}
					else
					{
						cout << "Failed to add publication!" << endl;
						delete that;
					}
				}
			}
		}
		cout << endl;
	}

	// Function to remove a publication from the library
	void LibApp::removePublication()
	{
		cout << "Removing publication from the library" << endl;
		int libref = search(1);
		if (libref)
		{
			if (confirm("Remove this publication from the library?"))
			{
				getPub(libref)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
		cout << endl;
	}

	// Function to checkout a publication from the library
	void LibApp::checkOutPub()
	{
		cout << "Checkout publication from the library" << endl;

		int libref = search(3);
		if (libref)
		{
			if (confirm("Check out publication?"))
			{
				cout << "Enter Membership number: ";
				int memberId = 0;
				bool ok = false;

				while (!ok)
				{
					cin >> memberId;
					if (!cin or memberId < 10000 or memberId > 99999) {
						std::cout << "Invalid membership number, try again: ";
						cin.clear();
						cin.ignore(3000, '\n');
					}
					else
					{
						ok = true;
					}
				}

				getPub(libref)->set(memberId);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
		cout << endl;
	}

	// The main run method of the LibApp class
	void LibApp::run()
	{
		while (true) // Repeatedly display and process the menu until the user chooses to exit
		{
			int selection = m_mainMenu.run();

			if (selection == 0)
			{
				if (!m_changed)
				{
					cout << "\n";
					cout << "-------------------------------------------" << endl;
					cout << "Thanks for using Seneca Library Application" << endl;
					break;
				}
				else
				{
					int exitSelection = m_exitMenu.run();
					if (exitSelection == 1)
					{
						save();
						cout << "\n";
						cout << "-------------------------------------------" << endl;
						cout << "Thanks for using Seneca Library Application" << endl;
						break;
					}
					else if (exitSelection == 2)
					{
						cout << "\n";
						continue;
					}
					else
					{
						if (confirm("This will discard all the changes are you sure?"))
						{
							cout << "\n";
							cout << "-------------------------------------------" << endl;
							cout << "Thanks for using Seneca Library Application" << endl;
							break;
						}
						else
						{
							continue;
						}

					}
				}
			}
			else if (selection == 1)
			{
				newPublication();
			}
			else if (selection == 2)
			{
				removePublication();
			}
			else if (selection == 3)
			{
				checkOutPub();
			}
			else if (selection == 4)
			{
				returnPub();
			}
		}
	}

	// LibApp Destructor
	LibApp::~LibApp()
	{
		for (int i = 0; i < m_nolp; i++)
		{
			delete m_ppa[i];
		}
	}

}