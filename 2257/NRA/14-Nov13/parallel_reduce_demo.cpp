// parallel_reduce_demo.cpp
// Compile with: g++ -std=c++17 -O2 -pthread parallel_reduce_demo.cpp -o reduce_demo
#include <iostream>
#include <vector>
#include <chrono>
#include <execution>
#include <numeric>  // For reduce

using namespace std;
using namespace std::chrono;

void reportTime( const char* msg, steady_clock::duration span ) {
   auto ms = duration_cast<milliseconds>(span);
   cout << msg << ": " << ms.count( ) << " ms" << endl;
}

int main( ) {
   const size_t size = 100000000;
   vector<double> vec( size, 0.25 );  // Each element 0.25

   // Sequential reduce
   auto start = steady_clock::now( );
   double sum_seq = reduce( execution::seq, vec.begin( ), vec.end( ), 0.0 );
   auto end = steady_clock::now( );
   cout << "Sequential sum: " << sum_seq << endl;
   reportTime( "Sequential reduce", end - start );

   // Parallel reduce
   start = steady_clock::now( );
   double sum_par = reduce( execution::par, vec.begin( ), vec.end( ), 0.0 );
   end = steady_clock::now( );
   cout << "Parallel sum: " << sum_par << endl;
   reportTime( "Parallel reduce", end - start );

   return 0;
}