#include <iostream>
#include <thread>
using namespace std;
int shared_counter = 0;

void increment( ) {
   for ( int i = 0; i < 1000; ++i ) {
      ++shared_counter; // increment shared counter
   }
}

int main( ) {
   thread t1( increment );
   thread t2( increment );

   t1.join( );
   t2.join( );

   std::cout << "Final counter value: " << shared_counter << std::endl;
   return 0;
}
