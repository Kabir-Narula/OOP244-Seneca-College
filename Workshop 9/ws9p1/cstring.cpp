//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 27/07/2023(Monday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CSTRING_H__
#define SDDS_CSTRING_H__

#include <cstdio>

namespace sdds
{
    // Copies the source character string into the destination character string.
    // It keeps copying characters until it finds the null terminator '\0' in the source string.
    void strCpy(char* destination, const char* source)
    {
        int i = 0;
        while (source[i] != '\0')
        {
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0'; // Add null terminator at the end of the copied string.
    }

    // Copies at most 'count' characters from the source character string into the destination character string.
    // It stops copying when 'count' characters have been copied or when it finds the null terminator '\0' in the source string.
    // If 'count' is greater than the length of the source string, the destination will be null-terminated.
    void strnCpy(char* destination, const char* source, int count)
    {
        int i = 0;
        while (i < count && source[i] != '\0')
        {
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0'; // Add null terminator at the end of the copied string.
    }

    // Compares two C-strings lexicographically.
    // It checks each character in the strings until it finds a mismatch or reaches the end of either string.
    // Returns 0 if the strings are the same, a positive value if 'str1' is greater, and a negative value if 'str2' is greater.
    int strCmp(const char* str1, const char* str2)
    {
        int i = 0;
        while (str1[i] != '\0')
        {
            if (str1[i] != str2[i])
            {
                return str1[i] - str2[i]; // Return the difference of the ASCII values of the mismatched characters.
            }
            i++;
        }
        return 0; // The strings are the same, so return 0.
    }

    // Compares at most 'count' characters of two C-strings lexicographically.
    // It checks each character in the strings until it finds a mismatch, reaches the end of either string, or compares 'count' characters.
    // Returns 0 if the first 'count' characters of the strings are the same.
    // Returns a positive value if 'str1' is greater, and a negative value if 'str2' is greater.
    int strnCmp(const char* str1, const char* str2, int count)
    {
        int i = 0;
        while (i < count)
        {
            if (str1[i] != str2[i])
            {
                return str1[i] - str2[i]; // Return the difference of the ASCII values of the mismatched characters.
            }
            if (str1[i] == '\0' || str2[i] == '\0')
            {
                break; // If a null terminator is found, stop comparing (reached the end of one of the strings).
            }
            i++;
        }
        return 0; // The first 'count' characters of the strings are the same, so return 0.
    }

    // Returns the length of the C-string in characters (excluding the null terminator).
    int strLen(const char* str)
    {
        int len = 0;
        while (str[len] != '\0')
        {
            len++; // Count each character until a null terminator is encountered.
        }
        return len; // Return the length of the string.
    }

    // Returns the address of the first occurrence of 'needle' in 'haystack' string.
    // If 'needle' is an empty string, it returns the 'haystack' string itself.
    // If no match is found, it returns nullptr.
    const char* strStr(const char* haystack, const char* needle)
    {
        if (*needle == '\0')
        {
            return haystack; // If the needle is an empty string, return the haystack itself.
        }

        int haystackLen = strLen(haystack);
        int needleLen = strLen(needle);

        for (int i = 0; i < (haystackLen - needleLen + 1); i++)
        {
            int j = 0;
            while (j < needleLen && haystack[i + j] == needle[j])
            {
                j++; // Check for each character if they match until the full needle is checked or a mismatch is found.
            }

            if (j == needleLen)
            {
                return &haystack[i]; // If all characters of the needle match, return the address of the start of the match in the haystack.
            }
        }

        return nullptr; // No match found, return nullptr.
    }

    // Concatenates the 'source' C-string to the end of the 'destination' C-string.
    // The 'destination' string must have enough memory allocated to hold both strings.
    void strCat(char* destination, const char* source)
    {
        int i = 0;
        while (destination[i] != '\0')
        {
            i++; // Find the end of the destination string.
        }

        int j = 0;
        while (source[j] != '\0')
        {
            destination[i] = source[j]; // Append the source string to the end of the destination string.
            i++;
            j++;
        }

        destination[i] = '\0'; // Add null terminator at the end of the concatenated string.
    }
}

#endif
