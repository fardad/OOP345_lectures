#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto beg = nums.begin();
   auto it = std::next(beg, 3);
   std::cout << "beginning: " << *beg << endl;
   std::cout << "Value at next iterator: " << *it << "\n"; // Output: Value at next iterator: 40
   return 0;
}