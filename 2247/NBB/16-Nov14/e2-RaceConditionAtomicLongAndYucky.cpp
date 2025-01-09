#include <thread>
#include <iostream>
using namespace std;
void prn( char ch, atomic<int>& count ) {
   while ( true ) {
      int current_count = count.load( );
      if ( current_count >= 1000 ) {
         break;  // Stop if the limit has been reached
      }
      current_count = count.fetch_add( 1 );
      if ( current_count < 1000 ) {  // Double-check after incrementing
         cout << ch;
      }
      else {
         break;
      }
   }
}

int main( ) {
   atomic<int> count( 0 );  // Shared atomic counter initialized to 0

   // Launch 3 threads with different characters
   thread t1( prn, '^', ref( count ) );
   thread t2( prn, '-', ref( count ) );
   thread t3( prn, '+', ref( count ) );

   // Join all threads
   t1.join( );
   t2.join( );
   t3.join( );

   cout << "\nFinal count value: " << count.load( ) << endl;
   return 0;
}
