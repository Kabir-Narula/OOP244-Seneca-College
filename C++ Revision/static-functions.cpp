#include <iostream>
using std::string;
using namespace std;

// INTRODUCTION TO STATIC FUNCTIONS----------------------------------------------------------------

class Carbon
{
public:
  static int x; // static members...
  static int y;

  void display()
  {
    cout << x << " " << y << endl; // function to display values of  x and y
  }
};

int Carbon::x; // static member initialization [x]
int Carbon::y; // static member initialization [y]

int main()
{

  // Carbon STATIC CLASS MEMBERS ACCESS----------------------------------------------------------------

  Carbon C1; //
  C1.x = 4;
  C1.y = 2;
  C1.display(); // Original value of [x] and [y] in [C1] will be displayed...

  Carbon C2;
  C2.x = 10;
  C2.y = 12;
  C2.display(); // Original value of [x] and [y] in [C2] will be displayed...
  C1.display(); // Values of [x] and [y] in [C1] will be pointed to new values in [C2] and modified value will be displayed....

  return 0; //
}