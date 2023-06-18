//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/17/2023(Wednesday)
//==============================================

#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds
{

    // Function prototype

    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src);

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len);

    // Compares two C-strings
    int strCmp(const char* s1, const char* s2);

    // strnCmp: Compares two C-strings upto "len" characters.
    int strnCmp(const char* s1, const char* s2, int len);

    // returns the lenght of the C-string in characters
    int strLen(const char* s);

    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2);

    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src);

}
#endif