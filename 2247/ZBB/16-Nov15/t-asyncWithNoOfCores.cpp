#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include <numeric>
typedef unsigned long long ull;

ull partial_sum( const std::vector<int>& data, size_t start, size_t end ) {
   ull sum{};
   for ( size_t i = start; i < end; i++ ) {
      sum += data[i];
   }
   return sum;
}

using clk = std::chrono::steady_clock;
int main( ) {
   std::vector<int> data( 100000000, 1 ); // Large vector of 1s
   size_t num_threads = 64;//std::thread::hardware_concurrency( );
   std::vector<std::future<ull>> futures;

   auto st = clk::now( );

   size_t chunk_size = data.size( ) / num_threads;

   for ( size_t i = 0; i < num_threads; i++ ) {
      size_t start_index = i * chunk_size;
      size_t end_index = (i + 1) * chunk_size;
      futures.push_back( std::async( std::launch::async, partial_sum, std::ref( data ), start_index, end_index ) );
   }

   ull total = 0;
   for ( auto& future : futures ) {
      total += future.get( );
   }

   auto en = clk::now( );

   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(en - st);
   std::cout << num_threads << " threads, Async sum: " << total << "\n";
   std::cout << "Time taken: " << duration << " milliseconds\n";

   return 0;
}
