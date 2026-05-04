#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = std::chrono::steady_clock;
int main( ) {
   int tx, ty;
   auto Seconds = clk::now( ) + chrono::seconds( 1 );
   std::thread tX( [&]( ) {for ( tx = 0; clk::now( ) < Seconds; cout << '^', tx++ ); } );
   std::thread tY( [&]( ) {for ( ty = 0; clk::now( ) < Seconds; cout << '_', ty++ ); } );
   cout << "GO!" << endl;
   tX.join( );
   tY.join( );
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "tY Printed " << ty << " characters!" << endl;
   return 0;
}
