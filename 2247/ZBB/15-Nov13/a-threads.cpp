//Resource Acquisition Is Initialization
#include <thread>
#include <iostream>
using namespace std;
void foo( char sign ) {
   for ( int i = 0; i < 100; i++ ) {
      cout << sign;
   }
}

int main( ) {
   thread tX = thread( foo, '^' );
   foo('-' );
   tX.join( );
   return 0;
}