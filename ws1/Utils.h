
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    // Function Prototypes
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}
#endif 

