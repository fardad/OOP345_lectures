
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = chrono::steady_clock;

void prn( char ch, clk::time_point seconds, int& num ) {
   for ( num = 0; clk::now( ) < seconds; cout << ch, num++ );
}

int main( ) {

   auto Seconds = clk::now( ) + chrono::seconds( 1 );
   int tx, ty, tz;
   thread tX( prn, '^', Seconds, ref( tx ) );
   thread tY( prn, '-', Seconds, ref( ty ) );
   thread tZ( prn, '+', Seconds, ref( tz ) );
   tX.join( );
   tY.join( );
   tZ.join( );
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "tZ printed " << tz << " characters!" << endl;
   cout << "Total: " << tx + ty + tz << endl;
   return 0;
}
