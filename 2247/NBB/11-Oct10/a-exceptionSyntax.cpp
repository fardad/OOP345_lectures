#include <iostream>
using namespace std;
void throwDouble( double d ) {
   throw d;
}
int main( void ) {
   int i;
   double d = 10;
   char str[] = "A Cstring!";
   for ( i = 0; i < 3; i++ ) {
      try {
         if ( i == 0 ) {
            throwDouble( d );
         }
         if ( i == 1 ) {
            throw str;
         }
         throw i;
         cout << "This will never happen!!!!!";
      }
      catch ( double de ) {
         cout << "A double exception is here: " << de << endl;
      }
      catch ( const char* cstre ) {
         cout << "A cString exception is here: " << cstre << endl;
      }
      catch ( ... ) {
         cout << "Something thing was thrown, I don't know what!" << endl;
      }
   }

   return 0;
}