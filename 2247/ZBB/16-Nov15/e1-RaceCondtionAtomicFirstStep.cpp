#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
void prn( char ch, atomic<int>& count, int& num ) {
   for ( num = 0; count < 1000 && cout << ch; num++ ) {
      count++;
   }
}
int main( ) {
   int tx{}, ty{}, tz{};
   atomic<int> counter = 0;
   thread tX( prn, '^', ref( counter ), ref( tx ) );
   thread tY( prn, '-', ref( counter ), ref( ty ) );
   thread tZ( prn, '+', ref( counter ), ref( tz ) );
   tX.join( );
   tY.join( );
   tZ.join( );
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "tZ printed " << tz << " characters!" << endl;
   cout << counter << " - " << tx + ty + tz << endl;
   return 0;
}
