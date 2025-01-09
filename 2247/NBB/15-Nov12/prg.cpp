#include <thread>
#include <iostream>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = std::chrono::steady_clock;
int main( ) {
   int tx, ty;
   std::atomic<char> whoGoes = 'n';
   auto Seconds = clk::now( ) + chrono::seconds( 1 );
   std::thread tX = std::thread( 
      [&]( ) {
         while ( whoGoes != 'x' ); 
         for ( tx = 0; clk::now( ) < Seconds; cout << '^', tx++ ); 
      } 
   );
   std::thread tY = std::thread( 
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
