#include <iostream>
#include <cstdlib>
using namespace std;
#define WIN 1
#define LNX 2

#define PLATFORM AS400

#if PLATFORM == WIN

void clrScr( ) {
   system( "cls" );
}

#elif  PLATFORM == LNX

void clrScr( ) {
   system( "clear" );
}
#else
void clrScr( ) {
   cerr << "Non-supporting platform!" << endl;
}
#endif


int main( ) {
   for ( int i = 0; i < 1000; i++, cout << 'x' );
   cin.ignore( 10000, '\n' );
   clrScr( );
   for ( int i = 0; i < 1000; i++, cout << 'y' );
   return 0;
}