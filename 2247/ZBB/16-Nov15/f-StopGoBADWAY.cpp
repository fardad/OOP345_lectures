#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = chrono::steady_clock;
int main( ) {
   int tx, ty;
   atomic<char> whoGoes = 'n';
   auto Seconds = clk::now( ) + chrono::seconds( 1 );
   thread tX(
      [&]( ) {
         while ( whoGoes != 'x' );
         for ( tx = 0; clk::now( ) < Seconds; cout << '^', tx++ );
      }
   );
   thread tY(
      [&]( ) {
         while ( whoGoes != 'y' );
         for ( ty = 0; clk::now( ) < Seconds; cout << '_', ty++ );
      }
   );
   cout << "GO!" << endl;
   whoGoes = 'x';
   tX.join( );
   Seconds = clk::now( ) + chrono::seconds( 1 );
   whoGoes = 'y';
   tY.join( );
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "tY Printed " << ty << " characters!" << endl;
   return 0;
}
