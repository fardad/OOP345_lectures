// deque_demo.cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
   deque<int> nums = { 10, 20, 30 };
   nums.push_front(5);
   nums.push_back(40);

   cout << "Deque: ";
   for (int n : nums) cout << n << " ";
   cout << endl;

   nums.pop_front();
   nums.pop_back();

   cout << "After popping ends: ";
   for (int n : nums) cout << n << " ";
   cout << endl;

   return 0;
}