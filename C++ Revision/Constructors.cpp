
#include <iostream>
using std::string;
using namespace std;

//  INTRODUCTION TO CONSTRUCTORS----------------------------------------------------------------

class Debug
{
private:
  char first;
  char second;

public:
  int x, y;
  char z;

  Debug(int a, int b)
  {
    x = a;
    y = b;
  }

  Debug(int *a, int *b, char *c)
  {
    x = *a;
    y = *b;
    z = *c;
  }

  void display()
  {
    if (z == '\0') // Check if 'z' is null character
    {
      cout << x << " " << y << endl;
    }
    else
    {
      cout << x << " " << y << " " << z << endl;
    }
  }
};

int main()
{

  // DEBUG CLASS MEMBERS ACCESS----------------------------------------------------------------

  char c = 'L';
  int a = 2;
  int b = 3; // Corrected character assignment

  Debug d1(2, 4);
  Debug d2(&a, &b, &c); // Pass the address of 'c'

  d1.display(); // Will display d1 since z is not assigned
  d2.display(); // Will display d2 since z is assigned

  return 0;
}