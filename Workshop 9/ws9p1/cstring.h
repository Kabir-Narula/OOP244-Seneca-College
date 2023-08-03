//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 27/07/2023(Monday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

#include <cstdio>
#include <iostream>

namespace sdds
{
    
    void strCpy(char* destination, const char* source);

   
    void strnCpy(char* destination, const char* source, int len);

    
    int strCmp(const char* s1, const char* s2);

   
    int strnCmp(const char* s1, const char* s2, int len);

    
    int strLen(const char* s);

 
    const char* strStr(const char* str1, const char* str2);

    
    void strCat(char* dest, const char* src);
}

#endif
