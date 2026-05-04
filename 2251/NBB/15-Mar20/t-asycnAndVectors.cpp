#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <future>
#include <mutex>
using namespace std;
using clk = std::chrono::steady_clock;
class Chars {
   char m_ch;
public:
   Chars( char ch ) :m_ch( ch ) { }
   int operator()( clk::time_point sec ) {
      int noc = 0;
      for ( ; clk::now( ) < sec; cout << m_ch, noc++ );
      return noc;
   }
};
int main( ) {
   auto Seconds = clk::now( ) + chrono::seconds( 3 );
   Chars tx( '^' ), ty( '-' ), tz( '_' );
   vector<future<int>> f;
   f.push_back( async( tx, Seconds ) );
   f.push_back( async( ty, Seconds ) );
   f.push_back( async( tz, Seconds ) );
   int x[3];
   for ( int i = 0; i < 3; i++ ) {
      x[i] = f[i].get( );
   }
   cout << endl;
   cout << "tX Printed " << x[0] << " characters!" << endl;
   cout << "ty Printed " << x[1] << " characters!" << endl;
   cout << "tz Printed " << x[2] << " characters!" << endl;
   return 0;
}
