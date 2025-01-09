#include <iostream>
#include <chrono>
#include <future>

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
   auto Seconds = clk::now( ) + chrono::seconds( 2 );
   Chars tx( '^' ), ty( '-' ), tz( '_' );
   future<int>
      f1 = async( tx, Seconds ),
      f2 = async( ty, Seconds ),
      f3 = async( tz, Seconds );
   int x = f1.get( ), y = f2.get( ), z = f3.get( );
   cout << endl;
   cout << "tX Printed " << x << " characters!" << endl;
   cout << "ty Printed " << y << " characters!" << endl;
   cout << "tz Printed " << z << " characters!" << endl;
   cout << "Total " << x + y + z << endl;
   return 0;
}
