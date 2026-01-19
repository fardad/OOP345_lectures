#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter( 0 ); // Atomic variable

void increment( ) {
   for ( int i = 0; i < 100000; ++i ) {
      ++counter; // Atomic operation (no race condition)
   }
}

int main( ) {
   std::thread t1( increment );
   std::thread t2( increment );

   t1.join( );
   t2.join( );

   std::cout << "Counter: " << counter << "\n"; // Always 200000
   return 0;
}