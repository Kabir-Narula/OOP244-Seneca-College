
#include <iostream>
using std::string;
using namespace std;

int main()
{

  // Basics OF REFERENCES --------------------------------

  int y = 10;
  int z = 12;
  cout << "Original value of (y) : " << y << endl;
  cout << "Original value of (z) is : " << z << endl;
  cout << "*********************************" << endl;
  int &ref = y;                                                        // Assigned the reference the value of y (10)..
  ref = z;                                                             //  Assigned the reference the value of z (12), as a result value of y changes to z (12)...
  cout << "Accessed value of (y) through reference : " << ref << endl; // prints 12 as reference stores z not y
  cout << "Value of (z) through reference : " << z << endl;

  return 0;
}
