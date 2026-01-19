#include <iostream>
#include <thread>
#include <mutex>
/*

task1 locks mtx1 ? waits for mtx2.
task2 locks mtx2 ? waits for mtx1.
Both threads wait forever, causing a deadlock.

*/
std::mutex mtx1, mtx2;

void task1( ) {
   std::lock_guard<std::mutex> lock1( mtx1 );
   std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) ); // Simulate work
   std::lock_guard<std::mutex> lock2( mtx2 ); // Waiting for mtx2
   std::cout << "Task 1 done\n";
}

void task2( ) {
   std::lock_guard<std::mutex> lock2( mtx2 );
   std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) ); // Simulate work
   std::lock_guard<std::mutex> lock1( mtx1 ); // Waiting for mtx1 (deadlock)
   std::cout << "Task 2 done\n";
}

int main( ) {
   std::thread t1( task1 );
   std::thread t2( task2 );

   t1.join( );
   t2.join( );

   return 0;
}