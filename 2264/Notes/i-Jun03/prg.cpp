#include <iostream>
using namespace std;
/*
abort(): send SIGABRT, ends immidiatly without cleanup

terminate(): it is automatically when exception escape

*/
int main() {
   cout << "About to abort!" << endl;
   abort(); // no cleanup
   return 0;
}