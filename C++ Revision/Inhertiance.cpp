
#include <iostream>
using std::string;
using namespace std;

class Ackerman
{
public:
  int a = 3;
  int b = 5;

  Ackerman(float x, float y)
  {
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;
  }

  Ackerman(float xa, float ya, const char *c)
  {
    cout << xa << " " << ya << " " << c << endl;
  }
};

class subAckerman : public Ackerman
{
public:
  // Constructor for subAckerman that calls Ackerman's constructor
  subAckerman(float x, float y) : Ackerman(x, y)
  {
  }

  int m;
  int n;

  void display(int q, int r)
  {
    m = q;
    n = r;
    cout << m << " " << n << endl;
  }

  void subDisplay()
  {
    cout << "Original values of Ackerman:" << a << " " << b << endl;
    cout << "****************************************************************" << endl;
    cout << "Original addresses of Ackerman:" << &a << " " << &b << endl;
  }
};

int main()
{
  Ackerman Levi(12, 13);
  Ackerman Mikasa(15, 15, "HELLO");

  cout << "Accessing a and b from the main function:" << endl;
  cout << "Levi: a = " << Levi.a << ", b = " << Levi.b << endl;
  cout << "Mikasa: a = " << Mikasa.a << ", b = " << Mikasa.b << endl;

  subAckerman Eren(11, 111); // Calling subAckerman's constructor

  Eren.display(11, 111); // Calling the display function from subAckerman

  return 0;
}
