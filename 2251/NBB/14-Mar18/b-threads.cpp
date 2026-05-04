#include <iostream>
#include <thread>
using namespace std;
void foo( char sign ) {
   for ( int i = 0; i < 100; i++ ) {
      cout << sign;
   }
}
void threads( ) {
   thread tX( foo, '^' );
   thread tY( foo, '-' );
   foo( '_' );
   tX.join( );
   tY.join( );
}
int main( ) {
   cout << "14-Mar17 - Multi processing!" << endl;
   threads( );
   return 0;
}