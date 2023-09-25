
#include <iostream>
using std::string;
using namespace std;

int main()
{

  //  BASICS OF POINTERS --------------------------------

  int a = 5;   // variable a with value initialized to 5
  int b = 8;   // variable b with value initialized to 8
  int *p = &a; // stores the address of a variable in pointer...
  int *q = &b; // stores the address of b variable in pointer
  cout << "\nOriginal value of (a): " << a << endl;
  cout << "Original address of (a): " << &a << endl; // directly printing address of a
  cout << "*********************************" << endl;
  cout << "Address of (a) by pointer is : " << p << endl; // prints the address of a stored in  pointer p
  cout << "Value of (a) by pointer is : " << *p << endl;  //  dereference the pointer to print the value of a stores in pointer [p]
  cout << "*********************************" << endl;
  // Changing the value of a nd b through Pointers.....
  *p = 32;                                    // changes the original value of a by pointer to 32
  *q = 64;                                    // changes the original value of b by pointer to 64
  cout << "New value of (a): " << *p << endl; // prints out modified value through pointer p
  cout << "New value of (b): " << *q << endl; //  prints out modified value through pointer q
  cout << endl;

  
  return 0;
}