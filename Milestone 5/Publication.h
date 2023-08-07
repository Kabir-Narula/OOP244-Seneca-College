/* Citation and Sources...
Final Project Milestone 5
Module: Publication.h
Filename: Publication.h
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





#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include "Streamable.h"
#include "Date.h"
namespace sdds
{
	class Publication : public Streamable
	{
		char* m_title{}; //holds a dynamic title for the publication
		char m_shelfId[5]{}; //Hold the location of the publication in the library. m_shelfId is a c-string that is exactly 4 characters long.
		int m_membership = 0; //This attribute is an integer to hold a 5 digit membership number of members of the library.
		int m_libRef = -1; //This serial number is used internally to uniquely identify each publication in the system.
	protected:
		Date m_date; //A Date object.In periodical publications, this date is used for the publish date of the item.


	public:
		Publication(); //constructor (default)
		//The rule of three:

		//Copy constructor
		Publication(const Publication& other);
		//copy assignment
		Publication& operator=(const Publication& other);
		//destructor
		~Publication();

		//Methods
		//Modifiers
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		//Queries
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.

		//Pure virtual function implementations
		bool conIO(std::ios& io)const;
		//Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
		std::ostream& write(std::ostream& os) const;
		//If the os argument is a console IO object (use conIO()), print shelfId, title, membership and date attributes as the following format (title is left-justified padded with dots)
		std::istream& read(std::istream& is);
		//Read all the values in local variables before setting the attributes to any values.
		//First, clear all the attributes by freeing the memoryand setting everything to their default values.
		operator bool() const;
		//Returns true if neither of the title or shelfId attributes is null or empty.Otherwise, it will return false.
	};
}

#endif // !SDDS_PUBLICATION_H_


