#include <iostream>
#include <vector>
#include <execution>
#include <chrono>
#include <numeric>

/*
transform_reduce args:
   exectuion policy      (std::execution::seq , par, par_unseq)
   iterator beg
   iterator end
   inital value off the result
   bin operation between elements
   function to apply to each alement

*/
using clk = std::chrono::steady_clock;
int main( ) {
   std::vector<int> data( 100000000, 1 );
   auto st = clk::now( );
   long long total = std::transform_reduce(
      std::execution::par,
      data.begin( ),
      data.end( ),
      0LL,
      std::plus<>( ),
      []( int value ) {return value; } // is applied to each element
   );
   auto en = clk::now( );
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(en - st);
   std::cout << "Sum: " << total << std::endl;
   std::cout << "Time: " << duration << " milliseconds\n";
   return 0;
}