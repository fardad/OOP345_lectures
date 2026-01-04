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