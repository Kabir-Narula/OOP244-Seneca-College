#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds {

    // Function prototypes

    // Copies the source character string into the destination
    void strCpy(char* des, const char* src);

    // Copies the source character string into the destination up to "len" characters.
    // The destination will be null terminated only if the number of characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len);

    // Compares two C-strings
    int strCmp(const char* s1, const char* s2);

    // strnCmp: Compares two C-strings up to "len" characters.
    int strnCmp(const char* s1, const char* s2, int len);

    // Returns the length of the C-string in characters
    int strLen(const char* s);

    // Returns the address of the first occurrence of "str2" in "str1"
    // Returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2);

    // Concatenates "src" C-string to the end of "des"
    void strCat(char* des, const char* src);

} // namespace sdds

#endif // SDDS_CSTRING_H
