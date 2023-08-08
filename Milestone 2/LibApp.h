/* Citation and Sources...
Final Project Milestone 2
Module: LibApp.h
Filename: LibApp.h
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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds
{
	class LibApp
	{
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		bool confirmAction(const char* message);
		void loadData();
		void saveData();
		void searchPublication();
		void returnPublicationtolibrary();
		void addNewPublicationtolibrary();
		void removePublication();
		void checkoutPublication();

	public:
		LibApp();
		void run();
	};
}
#endif // SDDS_LIBAPP_H
