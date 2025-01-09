
#include <thread>
#include <iostream>
using namespace std;
int main( ) {
   int tx, ty, tz;
   thread tX(
      [&]( ) {
         for ( tx = 0; tx < 100; cout << '^', tx++ );
      }
   );
   thread tY( [&]( ) {for ( ty = 0; ty < 200; cout << '_', ty++ ); } );
   thread tZ( [&]( ) {for ( tz = 0; tz < 50; cout << '-', tz++ ); } );
   tX.join( );
   tY.join( );
   tZ.join( );
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "tZ printed " << tz << " characters!" << endl;
   return 0;
}
