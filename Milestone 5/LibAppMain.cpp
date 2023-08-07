// Final Project
// Library Application Tester
// File  LibAppMain.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
/* Citation and Sources...
Final Project Milestone 5
Module: LibAppMain.cpp
Filename: LibAppMain.cpp
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
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "LibApp.h"
#include "Date.h"
#include "Menu.h"
using namespace sdds;

// Function to run the application with the given filename
void runApp(const char* filename) {
    size_t i{};
    char ch;
    char original[31] = "orig";
    // Creating the original file name by appending "orig" to the given filename
    while (filename[i]) original[4u + i] = filename[i++];
    original[4u + i] = char(0);

    // Copying original values to data file;
    std::ofstream outFile(filename);
    std::ifstream inFile(original);
    while (inFile.get(ch)) {
        outFile << ch;
    }
    outFile.close();
    inFile.close();

    // Setting test values
    sdds::sdds_day = 10;
    sdds::sdds_mon = 8;
    sdds::sdds_year = 2023;
    sdds::sdds_test = true;

    // Creating and running the LibApp with the provided filename
    sdds::LibApp app(filename);
    app.run();

    // Displaying the content of the file after the application run
    std::cout << "Content of " << filename << "\n=========>\n";
    inFile.open(filename);
    while (inFile.get(ch)) std::cout << ch;
    std::cout << "<=========\n";
}

int main() {
    // Creating a menu to select the data file
    Menu outFile("Select Data File");
    outFile << "LibRecsSmall.txt" << "LibRecs.txt";

    // Running the selected test based on the user's choice
    switch (outFile.run()) {
    case 1:
        std::cout << "Test started using small data: " << std::endl;
        runApp("LibRecsSmall.txt");
        break;
    case 2:
        std::cout << "Test started using big data: " << std::endl;
        runApp("LibRecs.txt");
        break;
    default:
        std::cout << "Aborted by user! " << std::endl;
        break;
    }

    return 0;
}
