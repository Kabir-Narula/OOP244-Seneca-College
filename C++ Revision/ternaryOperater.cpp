
#include <iostream>
using std::string;
using namespace std;
#include <string>

static int s_level = 1;
static int s_speed = 2;

int main(){
  
  s_speed = s_level > 5 ? 10 : 5;
  cout<< " S_speed " << s_speed << endl;

  s_level = 20;
  s_speed = s_level > 5 ? s_level > 10 ? 15 : 10 : 5;
  cout<< " S_speed " << s_speed << endl;

  return 0;
}