
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds
{
    // Functions
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif 
