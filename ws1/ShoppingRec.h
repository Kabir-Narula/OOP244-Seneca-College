
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

namespace sdds
{
    // Constant Value
    const int MAX_QUANTITY_VALUE = 50;
    const int MAX_TITLE_LENGTH = 50;

    // Structure
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    // Function Prototypes
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif 
