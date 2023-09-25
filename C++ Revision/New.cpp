#include <iostream>
#include <string>
using namespace std;

class Anime {
private:
    string M_name;

public:
    Anime() : M_name("Unknown") {}
    Anime(const string& name) : M_name(name) {}

    // Define a member function to access the name
    const string& getName() const {
        return M_name;
    }
};

int main() {
  
    Anime First;
    Anime Second("Attack On Titan");
    cout << First.getName() << endl; // Use the correct function name "getName"
    cout << Second.getName() <<endl;  
    
    
     // Dynamically allocate instances of Anime
    Anime* firstPtr = new Anime;
    Anime* secondPtr = new Anime("One Piece");

    // Access and print the names
    cout << firstPtr->getName() << endl;
    cout << secondPtr->getName() << endl;

    // Don't forget to release the allocated memory
    delete firstPtr;
    delete secondPtr;
    
    return 0;

}
