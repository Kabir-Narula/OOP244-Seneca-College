
#include <iostream>
using std::string;
using namespace std;

// INTRODUCTION TO CLASSES----------------------------------------------------------------
class Player
{
  // Not specifying the Class type , their members are set to default  private types....
  // int x, y;  // private members
  // int speed; // private members

public:
  // Initialized to Public type...
  int a = 4; // public members
  int b = 5;
  int *ptr1 = &a; // stores the address of (a)
  int *ptr2 = &b; // stores the address of (b)s3
  int nSpeed = 10;
  int *ptr3 = &nSpeed;        // stores the address of (nSpeed)
  void move(int *xa, int *ya) // function declared in private class ; int type pointers passed as parameters...
  {
    *ptr1 += *xa * *ptr3;                                  // dereferencing values to print new values for (a)
    *ptr2 += *ya * *ptr3;                                  // dereferencing values to print new values for (b)
    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl; // prints the new values of (a) and (b)

    *ptr1 += *xa * *ptr3;
    *ptr2 += *ya * *ptr3;
    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;
  }
};
int main()
{
  // PLAYER CLASS MEMBERS ACCESS----------------------------------------------------------------
  int x = 3;
  int y = 2;
  int *ptr4 = &x;
  int *ptr5 = &y;

  Player player1;       // created a object player1
  player1.move(&x, &y); // passed the address of (x)(y), in - void move(int *xa, int *ya)  pointer parameters.....
                        // cout << player1.move(*x,*y) << endl;
  // cout << player1.move << endl;

  return 0;
}