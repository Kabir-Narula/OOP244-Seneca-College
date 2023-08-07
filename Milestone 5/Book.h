/* Citation and Sources...
Final Project Milestone 5
Module: Book.h
Filename: Book.h
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


#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Publication.h"
namespace sdds
{
	class Book : public Publication
	{
		char* m_authorName; //holds an author's name Dynamically
	public:
		Book(); //default constructor
		//The rule of three
		//copy constructor
		Book(const Book& B);
		//copy assignment
		Book& operator=(const Book& B);
		//destructor
		~Book();
		//Methods
		// 
		//Returns the character "B".
		virtual char type()const;
		//Write method
		std::ostream& write(std::ostream& os) const;
		//Read method
		std::istream& read(std::istream& is);
		//set method
		void set(int memberId);
		//Operator bool method
		operator bool() const;
	};
}

#endif


