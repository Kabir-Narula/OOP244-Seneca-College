#include <iostream>
using std::string;
using namespace std;

class Character
{
private:
  string N_name;
  int A_age;

public:
  // Default constructor
  Character()
  {
    N_name = "Unknown";
    A_age = 0;
  }

  // Parameterized constructor
  Character(const string &Name, int Age) : N_name(Name), A_age(Age) {}

  const string &getName() const { return N_name; }
  int getAge() const { return A_age; }

  void setname(const string &O_Name)
  {
    N_name = O_Name;
  }

  void setAge(const int O_Age)
  {
    A_age = O_Age;
  }

  void print()
  {
    cout << N_name << " " << A_age << endl;
  }

  void newPrint(const string &O_Name, int O_Age)
  {
    cout << O_Name << " " << O_Age << endl;
  }

   friend ostream& operator<<(ostream& COUT, const Character& character) {
    COUT << character.N_name ;
    COUT << " " << character.A_age << endl;

    return COUT;
  }
};



int main()
{
 
  Character C;
  C.print();                // This will print "Unknown 0"
  C.newPrint("Mikasa", 22); // This will print "Mikasa 22"

  Character C1 = Character("Levi", 18);
  C1.print();              // This will print "Levi 18"
  C1.newPrint("Eren", 20); // This will print "Eren 20"

  Character C2;
  C2.setname("Armin");
  C2.setAge(19);
  C2.print();               // This will print "Armin 19"
  C2.newPrint("Sasha", 21); // This will print "Sasha 21"

 cout << "Description First Character: " << C1 << endl;
  return 0;
}
