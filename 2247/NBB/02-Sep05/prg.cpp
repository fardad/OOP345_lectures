
#include <iostream>
using namespace std;
int main( int argc, char* argv[], char* env[] ) {
   int i{};
   for ( ; i < argc; i++ ) {
      cout << i + 1 << "> " << argv[i] << endl;
   }
   i = 0;
   while ( env[i] ) {
      cout << (i + 1) << "> " << env[i] << endl;
      i++;
   }
   return 0;
}