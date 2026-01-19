#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   vector<int> numbers = { 10, 20, 30, 40, 50 };
   vector<int> sublist;

   // Copy the first 3 elements to sublist
   copy(numbers.begin(), numbers.begin() + 3, back_inserter(sublist));

   // Print the sublist
   cout << "Sublist: ";
   for (int num : sublist) {
      cout << num << " ";
   }

   return 0;
}