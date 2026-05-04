#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   vector<int> numbers = { 10, 20, 30, 40, 50 };

   // Find the first occurrence of 30
   auto it = find(numbers.begin(), numbers.end(), 30);

   if (it != numbers.end()) {
      cout << "Found 30 at position: " << distance(numbers.begin(), it) << endl;

      // Modify the found element
      *it = 35;  // Change 30 to 35
   }
   else {
      cout << "30 not found!" << endl;
   }

   // Print the modified vector
   cout << "Modified vector: ";
   for (int num : numbers) {
      cout << num << " ";
   }

   return 0;
}