#include <iostream>
using std::string;
using namespace std;

class Anime;

void printAnime(Anime* e);

class Anime {
public:
    int x;
    int y;

    Anime(int a, int b) {
        this->x = a;
        this->y = b;
        printAnime(this);
    }
};

void printAnime(Anime* e) {
    cout << e->x << " " << e->y << endl;
}

int main() {
    Anime a = Anime(1, 2);

    return 0;
}
