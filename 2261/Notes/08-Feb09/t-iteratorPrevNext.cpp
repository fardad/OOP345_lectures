#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
   cout << "OOP345 NBB - Feb 09" << endl;
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto it = std::next(nums.begin(), 3);

   std::cout << "Value at next iterator: " << *it << "\n"; // Output: Value at next iterator: 40
   auto it2 = std::prev(nums.end(), 2);

   std::cout << "Value at previous iterator: " << *it2 << "\n"; // Output: Value at previous iterator: 40
   return 0;
}