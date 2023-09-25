#include <iostream>
#include <string>
using namespace std;

class Anime {
protected:
    string a_name;
    int a_release;
    string a_theme;

public:
    Anime() {}
    Anime(const string &name, int release, const string &theme) : a_name(name), a_release(release), a_theme(theme) {}

    const string &getname() { return a_name; }
    int getRelease() { return a_release; }
    const string &getTheme() { return a_theme; }

    void setname(const string &A_name) { a_name = A_name; }
    void setRelease(int A_release) { a_release = A_release; }
    void setTheme(const string &A_theme) { a_theme = A_theme; }

    void printAnime() {
        cout << "Anime: " << a_name << ", Release Year: " << a_release << ", Theme: " << a_theme << endl;
    }
};

class Character : public Anime {
protected:
    string c_name;
    int c_age;
    string c_power;
    Anime &associatedAnime; // Reference to the associated anime

public:
    Character(Anime &anime, const string &name, int age, const string &power)
        : Anime(anime), c_name(name), c_age(age), c_power(power), associatedAnime(anime) {}

    void printCharacter() {
        cout << "Character Name: " << c_name << ", Age: " << c_age << ", Power: " << c_power << endl;
        associatedAnime.printAnime(); // Automatically print associated anime details.
    }
};

int main() {
    Anime firstAnime = Anime("AOT", 2000, "Action");
    firstAnime.printAnime();

    Character leviCharacter = Character(firstAnime, "Levi", 18, "Gear");
    leviCharacter.printCharacter();

    return 0;
}
