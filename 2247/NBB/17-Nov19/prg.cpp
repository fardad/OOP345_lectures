#include <iostream>
#include <cstdlib>
using namespace std;
#define LINUX 1
#define WINDOWS 2

#define PLATFORM WINDOWS

#if PLATFORM == WINDOWS
void wipe( ) {
   system( "cls" );
}
#elif PLATFORM == LINUX
void wipe( ) {
   system( "clear" );
}
#else
void wipe( ) {
   cerr << "Unsupported OS" << endl;
}

#endif


int main( ) {
   int i;
   for ( i = 0; i < 1000; i++, cout << i );
   cin.ignore( 1000, '\n' );
   wipe( );
   cout << "Clean" << endl;
   return 0;
}
