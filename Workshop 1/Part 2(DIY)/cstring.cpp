//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/17/2023(Wednesday)
//==============================================

#include <iostream>
#include "cstring.h"

namespace sdds
{
    void strCpy(char* des, const char* src)
    {
        int i = 0;
        while (src[i])
        {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

    int strLen(const char* s)
    {
        int i = 0;
        while (s[i])
        {
            i++;
        }
        return i;
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        while (i < len) {
            des[i] = src[i];
            i++;
        }
        // des[i] = '\0';
    }

    int strCmp(const char* s1, const char* s2)
    {
        int i = 0, comparison_result = 0;
        bool flag = true;
        while (flag)
        {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            {
                comparison_result = s1[i] - s2[i];
                flag = false;
            }

            i++;
        }
        return comparison_result;
    }

    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0, comparison_result = 0;
        bool flag = true;
        while (i < len && flag)
        {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            {
                comparison_result = s1[i] - s2[i];
                flag = false;
            }
            i++;
        }
        return comparison_result;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        int i = 0;
        const char* result = nullptr;
        bool flag = true;

        while (str1[i] && strLen(str1) > strLen(str2) && flag)
        {
            if (strnCmp(&str1[i], str2, strLen(str2)) == 0)
            {
                result = &str1[i];
                flag = false;
            }
            i++;
        }
        return result;
    }

    void strCat(char* des, const char* src)
    {
        int des_len = strLen(des);
        int index = 0;

        while (src[index])
        {
            des[des_len] = src[index];
            des_len++;
            index++;
        }
        des[des_len] = '\0';
    }
}