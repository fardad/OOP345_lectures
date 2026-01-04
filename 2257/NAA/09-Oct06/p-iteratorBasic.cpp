#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> nums = { 1, 2, 3, 4, 5 };

   for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
      cout << *it << " ";
   cout << endl;

   // Modern way
   for (auto it = nums.begin(); it != nums.end(); ++it)
      cout << *it << " ";
   cout << endl;

   return 0;
}