/* Citation and Sources...
Final Project Milestone 5
Module: Date.h
Filename: Date.h
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/08  Preliminary release
2023/02/08  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

//==============================================
// Name : Kabir Narula
// Email : Knarula9@myseneca.ca
// Student ID : 127962223
// Section : NAA
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

namespace sdds {
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
        "No Error",
        "cin Failed",
        "Bad Year Value",
        "Bad Month Value",
        "Bad Day Value"
    };
    const int  MIN_YEAR = 1500;

    class Date {
    private:
        int m_year; // an integer between the year 1500 till today
        int m_mon; // an integer between 1 and 12
        int m_day; // an integer between 1 and the number of days in the month.
        int m_ErrorCode; // an integer that holds the code that corresponds to an error that recently happened 
        // or ZERO if the date object is valid and ready to be used.
        int m_CUR_YEAR; // an integer that is automatically initialized to the 
        // current date of the system for validation purposes when a Date object is instantiated.

        int daysSince0001_1_1() const; // returns the number of days passed since the date 0001/1/1
        bool validate();             /* validates the date setting the error code and then returning the result
                                      true, if valid, and false if invalid. */
        void errCode(int);           // sets the error code
        int systemYear() const;       // returns the current system year
        bool bad() const;             // return true if the Date is in a mistaken state.
        int mdays() const;            // returns the number of days in the current month

    public:
        void setToToday();           // sets the date to the current date (system date)
        Date();                      // creates a date with the current date
        Date(int year, int mon, int day); /* create a date with assigned values
                                           then validates the date and sets the
                                           error code accordingly */
        int errCode() const;         // returns the error code or zero if the date is valid
        const char* dateStatus() const;  // returns a string corresponding to the current status of the date
        int currentYear() const;         // returns the m_CUR_YEAR value;

        // The read method
        std::istream& read(std::istream& is = std::cin);
        // The write method
        std::ostream& write(std::ostream& os = std::cout) const;

        // Operator overloads
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator>=(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;

        // Operator - method
        int operator-(const Date& other) const;
        // Bool type conversion operator
        operator bool() const;

    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);

    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;

}
#endif
