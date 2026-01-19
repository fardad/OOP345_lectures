#include <iostream>
using namespace std;
int main( int argc, char* argv[], char* env[] ) {
   cout << "02-Jan16 OOP345NBB" << endl;
   for ( int i = 0; i < argc; i++ ) {
      cout << i  << ": " << argv[i] << endl;
   }

   for ( int j = 0; env[j]; j++ ) {
      cout << j + 1 << ": " << env[j] << endl;
   }
   return 0;

}
