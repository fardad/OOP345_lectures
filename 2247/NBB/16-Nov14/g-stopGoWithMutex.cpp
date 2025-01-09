#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
using namespace std;
using clk = chrono::steady_clock;
int main( ) {
   int tx, ty;
   auto Seconds = clk::now( ) + chrono::seconds( 1 );
   mutex key;
   key.lock( );
   thread tX( [&]( ) {
      key.lock( );
      for ( tx = 0; clk::now( ) < Seconds; cout << '^', tx++ );
      Seconds = clk::now( ) + chrono::seconds( 1 );
      key.unlock( );
      } );
   thread tY( [&]( ) {
      key.lock( );
      for ( ty = 0; clk::now( ) < Seconds; cout << '_', ty++ );
      Seconds = clk::now( ) + chrono::seconds( 1 );
      key.unlock( );
      } );
   cout << "GO!" << endl;
   key.unlock( );
   tX.join( );
   tY.join( );
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "ty Printed " << ty << " characters!" << endl;
   return 0;
}