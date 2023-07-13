// Final Project Milestone 1 
// Date and Menu Modules
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"
#include "Menu.h"
#include "Utils.h"

//Please use putty for termial client on Matrix (https://www.putty.org/)
//#define SDDS_LINUX  // Comment this to run on windows, 
                      // Uncommnet the above line to run on linux

#ifdef SDDS_LINUX  // Linux or Mac Console Colors
const char col_grey[] = "\e[38;5;8m";
const char col_red[] = "\e[38;5;9m";
const char col_green[] = "\e[38;5;10m";
const char col_yellow[] = "\e[38;5;11m";
const char col_blue[] = "\e[38;5;12m";
const char col_pink[] = "\e[38;5;13m";
const char col_cyan[] = "\e[38;5;14m";
const char col_white[] = "\e[38;5;15m";
const char col_end[] = "\e[0m";
#else  // Windows Console Colors
const char col_grey[] = "\033[38;5;8m";
const char col_red[] = "\033[38;5;9m";
const char col_green[] = "\033[38;5;10m";
const char col_yellow[] = "\033[38;5;11m";
const char col_blue[] = "\033[38;5;12m";
const char col_pink[] = "\033[38;5;13m";
const char col_cyan[] = "\033[38;5;14m";
const char col_white[] = "\033[38;5;15m";
const char col_end[] = "\033[0m";
#endif


using namespace std;
using namespace sdds;

const char instructionMessages[10][81] = {
   ">>>>>Enter 0 and then 0 again",
   ">>>>>Enter 1",
   ">>>>>Enter 1 again",
   ">>>>>Enter 2",
   ">>>>>Enter 1",
   ">>>>>Enter 3",
   ">>>>>Enter 4 and then 3",
   ">>>>>Enter -1 and then 3",
   ">>>>>Enter abc and then 1",
   ">>>>>Enter 0 and then 0 again"
};
// A fool proof Date entry from console 
Date getDate();
void dateOperatorTester(const Date& A, const Date& B);
void showOrder(const unsigned int* cnt, const Menu& M);
void dateTester();
void menuTester();
void hr();

int main() {
    cout << col_red << "Testing Date module:" << col_end << endl;
    dateTester();
    cout << col_red << "testing Menu Module:" << col_end << endl;
    menuTester();
    return 0;
}

void hr() {
    cout << col_blue << "------------------------------------------" << col_end << endl;
}
void menuTester() {
    unsigned int selections[3] = { 0 };
    unsigned int s;
    int mesIndex;
    Menu m1("Lunch Menu"), m2;
    if (!m2) {
        cout << "The >" << m2 << "< menu is empty" << endl;
    }
    else {
        cout << "Wrong output, your bool cast is done incorrenctly!";
    }
    m1 << "Omelet" << "Tuna Sandwich" << "California Roll";
    m2 << "Order more";
    if (m1) {
        cout << "The " << m1 << " is not empty and has " << (unsigned int)(m1) << " menu items." << endl;
    }
    else {
        cout << "Wrong output, your bool cast is done incorrenctly!";
    }
    for (mesIndex = 0; mesIndex < 10; mesIndex++) {
        if (mesIndex == 0) cout << col_pink << instructionMessages[mesIndex] << col_end << endl;
        do {
            if (mesIndex > 0) cout << col_pink << instructionMessages[mesIndex++] << col_end << endl;
            s = m1.run();
            if (s) {
                selections[s - 1]++;
                cout << "you chose " << m1[s - 1] << endl;
            }
        } while (s != 0 || ~m2 != 0);
        showOrder(selections, m1);
    }
}
void showOrder(const unsigned int* cnt, const Menu& M) {
    bool orderedSomthing = false;
    cout << "Your orders: " << endl;
    for (int i = 0; i < 3; i++) {
        if (cnt[i]) {
            orderedSomthing = true;
            cout << cnt[i] << " " << M[i] << (cnt[i] > 1 ? "s" : "") << endl;
        }
    }
    if (!orderedSomthing) cout << "You didn't order anything!" << endl;
}





void dateTester() {
    Date
        D1,   // daysSince0001_1_1 to be recieved from console
        D2(2023, 6, 26);

    cout << D1 - D2 << " days since ms1 was published" << endl;
    cout << "Current Date: " << D1 << endl;
    cout << "Enter " << col_pink << "abc: " << col_end;
    cin >> D1;
    cout << D1 << endl;
    cout << "Enter " << col_pink << "1000/1/1: " << col_end;
    cin >> D1;
    cout << D1 << endl;
    cout << "Enter " << col_pink << "2025/1/1: " << col_end;
    cin >> D1;
    cout << D1 << endl;
    cout << "Enter " << col_pink << "2000/13/1: " << col_end;
    cin >> D1;
    cout << D1 << endl;
    cout << "Enter " << col_pink << "2000/1/0: " << col_end;
    cin >> D1;
    cout << D1 << endl;
    hr();
    D1 = Date(2023, 6, 26);
    D2 = Date(2023, 6, 26);
    dateOperatorTester(D2, D1);
    hr();
    D2 = Date(2022, 6, 26);
    dateOperatorTester(D2, D1);
    hr();
    D2 = Date(2024, 6, 26);
    dateOperatorTester(D2, D1);
    hr();
}

Date getDate() {
    Date D;
    do {
        cin >> D;      // get D from console
    } while (!D && cout << D.dateStatus() << ", Please try again > ");  // if D is invalid, print error message and loop
    return D;
}
void dateOperatorTester(const Date& A, const Date& B) {
    cout << "All the following statements must be correct: " << endl;
    if (B > A) {
        cout << B << " > " << A << endl;
    }
    else {
        cout << B << " <= " << A << endl;
    }
    if (B < A) {
        cout << B << " < " << A << endl;
    }
    else {
        cout << B << " >= " << A << endl;
    }
    if (B <= A) {
        cout << B << " <= " << A << endl;
    }
    else {
        cout << B << " > " << A << endl;
    }
    if (B >= A) {
        cout << B << " >= " << A << endl;
    }
    else {
        cout << B << " < " << A << endl;
    }
    if (B == A) {
        cout << B << " == " << A << endl;
    }
    else {
        cout << B << " != " << A << endl;
    }
    if (B != A) {
        cout << B << " != " << A << endl;
    }
    else {
        cout << B << " == " << A << endl;
    }
    cout << "Days between the two dates: " << B - A << endl;
}
