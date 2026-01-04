// execution_policies_demo.cpp
// Compile with: g++ -std=c++17 -O2 -pthread execution_policies_demo.cpp -o demo
#include <iostream>
#include <vector>
#include <chrono>
#include <execution>  // For execution policies
#include <algorithm>  // For transform

using namespace std;
using namespace std::chrono;

// Function to report time
void reportTime( const char* msg, steady_clock::duration span ) {
   auto ms = duration_cast<milliseconds>(span);
   cout << msg << ": " << ms.count( ) << " ms" << endl;
}

int main( ) {
   const size_t size = 100000000;  // 100 million elements
   vector<double> vec( size, 1.0 );  // Initialize with 1.0

   // Sequential transform: square each element
   auto start = steady_clock::now( );
   transform( execution::seq, vec.begin( ), vec.end( ), vec.begin( ), []( double x ) { return x * x; } );
   auto end = steady_clock::now( );
   reportTime( "Sequential transform", end - start );

   // Refill to reset
   fill( vec.begin( ), vec.end( ), 1.0 );

   // Parallel transform: square each element
   start = steady_clock::now( );
   transform( execution::par, vec.begin( ), vec.end( ), vec.begin( ), []( double x ) { return x * x; } );
   end = steady_clock::now( );
   reportTime( "Parallel transform", end - start );

   // Check a sample value (should be 1.0 after squaring 1.0)
   cout << "Sample value: " << vec[0] << endl;

   return 0;
}