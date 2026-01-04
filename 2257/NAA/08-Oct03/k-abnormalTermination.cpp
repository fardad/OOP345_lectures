/*

Abnormal Exits
terminate() – called when exceptions escape or handlers fail.
abort() – sends SIGABRT, ends immediately without cleanup.


*/

#include <iostream>
using namespace std;

int main() {
   cout << "About to abort!" << endl;
   abort(); // no cleanup
   return 0;
}