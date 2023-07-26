#define _crt_secure_no_warnings
#include <iostream>
#include "LibApp.h"
using namespace std;
int main() {
	sdds::LibApp theApp;
	cout << endl << "Testing exiting with no change:" << endl;
	theApp.run();
	cout << endl << "Testing exiting with change and discarding data:" << endl;
	theApp.run();
	cout << endl << "Testing exiting with change and saving data:" << endl;
	theApp.run();
	cout << endl << "Testing all actions:" << endl;
	theApp.run();
	return 0;
}
/* data to be entered:
 1- 1
 2- 0
 3- 0
 4- 2
 5- 1
 6- 0
 7- 0
 8- 1
 9- 3
10- 1
11- 0
12- 1
13- 4
14- 0
15- 2
16- 0
17- 1
*/