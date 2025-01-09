#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int shared_counter = 0;
mutex mtx;

void increment( ) {
   for ( int i = 0; i < 1000; ++i ) {
      lock_guard<mutex> lock( mtx ); // only one thread can enter here at a time
      ++shared_counter;
   }
}

int main( ) {
   thread t1( increment );
   thread t2( increment );

   t1.join( );
   t2.join( );

   cout << "Final counter value: " << shared_counter << endl;
   return 0;
}
