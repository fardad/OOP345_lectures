#include <thread>
#include <iostream>
using namespace std;
void prn( char ch, atomic<int>& count ) {
   while ( count.load( ) < 1000 && count.fetch_add( 1 ) < 1000 && cout << ch );
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
