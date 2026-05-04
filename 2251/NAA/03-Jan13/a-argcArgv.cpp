// as practice, 
// write an application and change the name of the exectuable to add.exe
// write the program so if the exectuable is ran as follows:
// add 123 234<ENTER>
// 357
// that is the sum of the two incoming arguments

#include <iostream>
using namespace std;
int main(int argc , char* argv[] ) {
   for ( int i = 0; i < argc; i++ ) {
      cout << i << ": " << argv[i] << endl;
   }
   return 0;
}