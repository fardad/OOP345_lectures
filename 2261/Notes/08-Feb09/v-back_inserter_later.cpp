#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
   cout << "OOP345 NBB - Feb 09" << endl;
   std::vector<int> nums = { 10, 20, 30 };
   std::vector<int> to_copy = { 40, 50 };
   // Creates an iterator that appends elements to the back of a container.
   std::copy(to_copy.begin(), to_copy.end(), std::back_inserter(nums));

   for (int n : nums)
      std::cout << n << " "; // Output: 10 20 30 40 50
   return 0;
}