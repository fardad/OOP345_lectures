#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;
using clk = std::chrono::steady_clock;
void chars( int& n, clk::time_point sec, char ch ) {
   for ( n = 0; clk::now( ) < sec; cout << ch, n++ );
}
int main( ) {
   int tx, ty, tz, ti, tj;
   clk::time_point Seconds = clk::now( ) + chrono::seconds( 3 );
   vector<thread> thrds;
   thrds.push_back( thread( chars, ref( tx ), Seconds, '^' ) );
   thrds.push_back( thread( chars, ref( ty ), Seconds, '-' ) );
   thrds.push_back( thread( chars, ref( tz ), Seconds, '_' ) );
   thrds.push_back( thread( chars, ref( ti ), Seconds, '+' ) );
   thrds.push_back( thread( chars, ref( tj ), Seconds, '$' ) );
   for ( auto& t : thrds ) {
      t.join( );
   }
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "ty Printed " << ty << " characters!" << endl;
   cout << "ty Printed " << tz << " characters!" << endl;
   cout << "ty Printed " << ti << " characters!" << endl;
   cout << "ty Printed " << tj << " characters!" << endl;
   return 0;
}
