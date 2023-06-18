// Workshop 1:
// Version: 0.91 
//  (removed #include <cstring> that was included by mistake)
// Date: 2021/10/16
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
///////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"

using namespace sdds;
using namespace std;

#ifndef SDDS_CSTRING_H
#error "The header guard doesn't follow the convention!"
#endif

int main() {
	char str1[80] = "abcdefghijklmnopqrstuvwxyz";
	char str2[80];
	const char* fadd;

	sdds::strCpy(str2, str1);
	cout << str2 << endl;

	sdds::strnCpy(str2, "@@@", 2);
	cout << str2 << endl;

	sdds::strnCpy(str2, "@@@", 3);
	cout << str2 << endl;

	sdds::strnCpy(str2, "@@@", 4);
	cout << str2 << endl;

	cout << sdds::strCmp("aab", "aaa") << endl;
	cout << sdds::strnCmp("aab", "aaa", 2) << endl;
	cout << sdds::strnCmp("aab", "aaa", 3) << endl;
	cout << sdds::strLen("") << endl;
	cout << sdds::strLen(str1) << endl;

	fadd = sdds::strStr(str1, "jkl");
	cout << fadd << endl;

	fadd = sdds::strStr(str1, "bbb");
	if (!fadd)
		cout << "Not found" << endl;

	sdds::strCpy(str2, "John ");
	sdds::strCat(str2, "Doe");
	cout << str2 << endl;

	return 0;
}