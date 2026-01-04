// array_example.cpp
#include <iostream>
#include <array>
using namespace std;

int main() {
   array<int, 5> nums = { 1, 2, 3, 4, 5 };

   cout << "Size: " << nums.size() << endl;
   cout << "Front: " << nums.front() << ", Back: " << nums.back() << endl;

   // Range-based for
   for (int n : nums)
      cout << n << " ";
   cout << endl;

   // Modify element
   nums[2] = 99;
   cout << "Modified: ";
   for (auto n : nums) cout << n << " ";
   cout << endl;

   return 0;
}