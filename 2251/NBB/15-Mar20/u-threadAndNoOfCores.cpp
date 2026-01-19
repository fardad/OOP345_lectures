#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
void partial_sum( const vector<int>& data, long long& sum, size_t start, size_t end ) {
   for ( size_t i = start; i < end; i++ ) {
      sum += data[i];
   }
}
int main( ) {
   vector<int> data( 100000000, 1 ); // Large vector of 1s
   long long total = 0;
   size_t num_threads = thread::hardware_concurrency( );
   vector<thread> threads;
   vector<long long> partial_sums( num_threads, 0 );

   size_t chunk_size = data.size( ) / num_threads;
   for ( size_t i = 0; i < num_threads; i++ ) {
      size_t start = i * chunk_size;
      size_t end = (i + 1) * chunk_size;
      threads.push_back( thread( partial_sum, ref( data ), ref( partial_sums[i] ), start, end ) );
   }
   for ( thread& t : threads ) {
      t.join( );
   }
   for ( long long value : partial_sums ) {
      total += value;
   }
   cout << num_threads << "-threaded sum : " << total << "\n";

   return 0;
}
