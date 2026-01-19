#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
   std::vector<int> nums = { 1, 2, 2, 4, 5 };
   int count = std::count( nums.begin( ), nums.end( ), 2);

   std::cout << "Count of 2: " << count << "\n";
   return 0;
}