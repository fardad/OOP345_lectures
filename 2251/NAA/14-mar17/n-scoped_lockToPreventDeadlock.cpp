#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void task( int id ) {
   std::scoped_lock lock( mtx1, mtx2 ); // Locks both mutexes safely
   std::cout << "Task " << id << " done\n";
}

int main( ) {
   std::thread t1( task, 1 );
   std::thread t2( task, 2 );

   t1.join( );
   t2.join( );

   return 0;
}