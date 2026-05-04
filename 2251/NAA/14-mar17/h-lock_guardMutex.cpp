#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment( ) {
   for ( int i = 0; i < 100000; ++i ) {
      std::lock_guard<std::mutex> lock( mtx ); // Lock to prevent race condition
      ++counter;
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