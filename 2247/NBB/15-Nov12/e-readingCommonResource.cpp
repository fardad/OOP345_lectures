#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = std::chrono::steady_clock;

void prn( char ch, clk::time_point seconds, int& num ) {
   for ( num = 0; clk::now( ) < seconds; cout << ch, num++ );
}

int main( ) {

   auto Seconds = clk::now( ) + chrono::seconds( 1 );
   int tx, ty, tz;
   std::thread tX = std::thread( prn, '^', Seconds, ref( tx ) );
   std::thread tY = std::thread( prn, '-', Seconds, ref( ty ) );
   std::thread tZ = std::thread( prn, '+', Seconds, ref( tz ) );
   tX.join( );
   tY.join( );
   tZ.join( );
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "tZ printed " << tz << " characters!" << endl;
   return 0;
}
