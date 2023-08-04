///==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 03/08/2023
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "searchNlist.h"
using namespace std;
using namespace sdds;

int main() {
    Car C[8] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"),
                 Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"),
                 Car("GVDEFG", "Tesla Model X") };
    Student S[6] = { Student(23456, "Lisa Simpson",4.0),Student(45678, "Ralph Wiggum",2.1), Student(56789, "Milhouse Van Houten",4.0),
                 Student(67890, "Todd Flanders", 3.5), Student(34567, "Nelson Muntz",3.0),Student(12345, "Bart Simpson",1.5) };
    Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56,111), Employee(122345, "Mindy Simmons", 65432.44,222),
                 Employee(435678, "Lenny Leonard", 43213.22,111), Employee(546789, "Waylon Smithers", 654321.55,333),
                 Employee(657890, "Frank Grimes", 34567.88,333), Employee(364567, "Homer Simpson", 55432.11,111) };

    Collection<Car> Cres;
    Collection<Student> Sres;
    Collection<Employee>Eres;

    // Call the  listArrayElements to list all cars, Title: "All the cars:"
    listArrayElements("All the cars:", C, 8);
    cout << "Searching for Tesla cars: " << endl;
    // Call the search function to search the array C 
    // and store the matches in Cres passing "Tesla" as the key argument
    if (search(Cres, C, 8, "Tesla")) {
        cout << Cres.size() << " match" << (Cres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Cres.size(); i++) {
            cout << (i + 1) << ": " << Cres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    // Call the  listArrayElements to list all the students, Title: "All students:"
    listArrayElements("All students:", S, 6);

    cout << "Searching for students with 4.0 Gpa:" << endl;
    // Call the search function to search the array S 
    // and store the matches in Sres passing 4.0 as the key argument
    if (search(Sres, S, 6, 4.0)) {
        cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Sres.size(); i++) {
            cout << (i + 1) << ": " << Sres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    // Call the  listArrayElements to list all the employees, Title: "All employees:"
    listArrayElements("All employees", E, 6);

    cout << "Searching for employees who share office number 111:" << endl;
    // Call the search function to search the array E 
    // and store the matches in Eres passing 111 as the key argument
    if (search(Eres, E, 6, 111)) {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++) {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    cout << "Searching for employees who share office number 555:" << endl;
    // Call the search function to search the array E 
    // and store the matches in Eres passing 555 as the key argument
    if (search(Eres, E, 6, 555)) {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++) {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    int a[]{ 10,20,30,40,50,60 };
    // Call the  listArrayElements to list all the integers in the array a
    // Title: "INTEGERS"

    listArrayElements("INTEGERS", a, 6);
    return 0;
}