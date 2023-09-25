
#include <iostream>
using std::string;
using namespace std;
#include <string>

class Anime{
 private:
string A_name;

public:
Anime(): A_name("Unknown"){}
Anime(const string& name): A_name(name){};

const string getName() const { return A_name; }



};



int main(){


  Anime anime; // calls the dEFAULT CONSTRUCTOR
  cout<< anime.getName() << endl; // on the stack...

  Anime* a;{
  
  Anime* a1 = new Anime("Attack on Titan");  // on the HEAP.....
  a = a1;
  cout << a->getName() << endl;
 // cout << (*a).getName() << endl;
  delete a; 
  }


  return 0;
}