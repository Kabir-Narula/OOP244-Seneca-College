#include <iostream>
using std::string;
using namespace std;
#include <array>

class Entity{

public:
  static const int anotherexampleSize = 5; // need to be static and constant in the c++
  int newExample[anotherexampleSize]; // the only way we can allocate memory size using static const........

  array<int, 5> Another; // new way to declare array

  int* example = new int[5];

  Entity()
  {
    for (int i  = 0 ; i < 5 ; i++)
    example[i] = 2;
  }
};



int main()
{

  Entity e ;
  

  

   


  

  
  return (0);
}
