#include <iostream>
#include <list>
using namespace std;

int main() {
   list<int> nums = { 10, 20, 30, 40 };
   auto it = nums.begin();
   auto cit = nums.cbegin();// if you need read-only iterator, use cbegin and cend
   advance(it, 2);

   nums.insert(it, 25); // insert before 30
   nums.erase(--it);    // erase 20

   for (int n : nums) cout << n << " ";
   cout << endl;
   return 0;
}