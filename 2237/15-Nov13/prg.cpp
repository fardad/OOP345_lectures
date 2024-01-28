#include <iostream>
#include <vector>
#include <execution>
#include <chrono>
#include <numeric>

/*
stransform_reduce args:
   exectuion policy      (std::execution::seq , par, par_unseg)
   iterator beg
   iterator end
   inital value off the result
   bin operation between elements
   function to apply to each alement

*/
int main() {
   std::vector<int> data(100000000, 1);
   auto start = std::chrono::high_resolution_clock::now();
   long long total = std::transform_reduce(
      std::execution::par,
      data.begin(),
      data.end(),
      0LL,
      std::plus<>(),
      [](int value) {return value; }
   );
   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> diff = end - start;
   std::cout << "Sum: " << total << std::endl;
   std::cout << "Time: " << diff.count() << " seconds\n";
   return 0;
}