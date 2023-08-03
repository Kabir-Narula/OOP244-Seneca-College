//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/17/2023(Wednesday)
//==============================================
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "ShoppingRec.h"

#include "Utils.h"

using namespace std;
namespace sdds
{

    ShoppingRec getShoppingRec()
    {
        ShoppingRec R = {};
        cout << "Item name: ";
        readCstr(R.m_title, MAX_TITLE_LENGTH);
        cout << "Quantity: ";
        R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
        return R;
    }
    void displayShoppingRec(const ShoppingRec* shp)
    {
        cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title << " qty:(" << shp->m_quantity << ")" << endl;
    }
    void toggleBoughtFlag(ShoppingRec* rec)
    {
        rec->m_bought = !rec->m_bought;
    }
    bool isShoppingRecEmpty(const ShoppingRec* shp)
    {
        return shp->m_title[0] == 0;
    }

}