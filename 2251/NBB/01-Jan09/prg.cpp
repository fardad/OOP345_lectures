#include <iostream>
using namespace std;

int main( int argc, char* argv[], char* env[] ) {
   for ( int i = 0; i < argc; i++ ) {
      cout << i + 1 << ": " << argv[i] << endl;
   }

   for ( int j = 0; env[j]; j++ ) {
      cout << j + 1 << ": " << env[j] << endl;
   }
   return 0;

}
