/*
Containers – structures that hold data (vector, list, map, set)
Iterators – objects that traverse containers
Algorithms – functions that operate on ranges (sort, find, count, etc.)
Function objects – callable objects (e.g., std::less, std::greater)

*/

// stl_example.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   vector<int> nums = { 5, 2, 9, 1, 3 };
   sort(nums.begin(), nums.end());
   for (int n : nums) cout << n << " ";
   cout << endl;

   if (binary_search(nums.begin(), nums.end(), 3))
      cout << "3 found!" << endl;
   return 0;
}