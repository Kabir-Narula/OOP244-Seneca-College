
#include <iostream>
using std::string;
using namespace std;
#include <string>

class Anime
{
private:
  string M_name;
  int age;

public:
  const string &getName() const // used reference to string instead of creating copies....
  {

    return M_name;    
  }

  void setName(const string oldname) // cannot be modified afterwards....
  {
   M_name = oldname;
  }

  void printName(){

    cout<< "Anime name is - " << M_name <<endl; // function to print the name of anime....
  }
};

// Two ways to define the strings.....

int main()
{
  Anime myAnime;
  myAnime.setName("Attack on Titan");
   
  myAnime.printName();

  

  const char *Name = "Levi"; // using pointers to declare the string..
  cout << Name << endl;

  string name = "LEVI";
  cout << name << endl;
  // cout<<name.size() << endl;  // we cannot use this because it is declared as const pointer....

  name += " Ackerman";
  cout << name << endl;

  return 0;
}