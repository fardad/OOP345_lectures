// write a program called findenv
// the program works as follows:
// findenv [envVar]<ENTER>
// prints  help message f argument is not provided
// prints the value of the environment variable if found 
// or "[envVar] not defined!" message if not found
// envfind Logname<ENTER>
// fardad.soleimanloo
#include <iostream>
using namespace std;
int main(int argc , char* argv[], char* env[] ) {
   for ( int i = 0; i < argc; i++ ) {
      cout << i << ": " << argv[i] << endl;
   }
   for ( int e = 0; env[e]; e++ ) {
      cout << e << ": " << env[e] << endl;
   }
   return 0;
}