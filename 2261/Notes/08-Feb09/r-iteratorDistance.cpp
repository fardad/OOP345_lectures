#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
   cout << "OOP345 NBB - Feb 09" << endl;
   std::vector<int> nums = { 10, 20, 30, 40, 50 };
   auto start = nums.begin();
   auto end = nums.end();

   int dist = std::distance(start, end);
   std::cout << "Distance: " << dist << "\n"; // Output: Distance: 5
   return 0;
}