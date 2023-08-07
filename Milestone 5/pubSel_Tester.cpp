// Final Project 
// PublicationSelector Usage demonstration
// File	pubSel_Tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//                    
/////////////////////////////////////////////////////////////////

//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
using namespace sdds;

// prints the publication with the library reference number "ref:
void prnPub(Publication* p[], int size, int ref) {
   int i;
   for (i = 0; i < size; i++) {
      if (ref == p[i]->getRef()) {
         cout << *p[i] << endl;
         i = size; // Exit the loop.
      }
   }
}
int main() {

   ifstream infile("LibRecs.txt");
   Publication* p[1000]{};
   PublicationSelector ps("Publications with Harry and MoneySencse", 5);
   char type{};
   int i;
   for (i = 0; infile; i++) {
      infile >> type;
      infile.ignore();
      if (infile) {
         if (type == 'P')
            p[i] = new Publication;
         else if (type == 'B')
            p[i] = new Book;
         if (p[i]) {
            infile >> *p[i];
            // find publications with Harry or MoneySence in the title
            if (strstr(*p[i], "Harry") || strstr(*p[i], "MoneySense"))
               ps << p[i]; // insert into PublicationSelector if there is match
         }
      }
   }
   if (ps) {
      ps.sort(); // sort them based on date and title
      int ref = ps.run(); // display the publications and select one
      if (ref) {
         cout << "Selected Library Reference Number: " << ref << endl;
         prnPub(p, 100, ref);
      }
      else {
         cout << "Aborted by user!";
      }
   }
   else {
      cout << "No matches to \"Harry\" and \"MoneySense\" found" << endl;
   }
   for (i = 0; p[i]; i++) {  //free the allocated memory
      delete p[i];
   }
   return 0;
}
