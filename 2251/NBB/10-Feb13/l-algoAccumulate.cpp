#include <iostream>
#include <vector>
#include <numeric>

int main() {
   std::vector<int> nums = { 1, 2, 3, 4, 5 };
   int sum = std::accumulate(nums.begin(), nums.end(), 10);

   std::cout << "Sum: " << sum << "\n";
   return 0;
}