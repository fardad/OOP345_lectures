#include <iostream>
#include <set>
using namespace std;
//Use Case: Use set when you need unique elements and automatic sorting.
int main() {
   set<int> numbers = { 30, 10, 20 };  // Automatically sorted

   // Add elements
   numbers.insert(25);
   numbers.insert(10);              // Duplicate ignored

   // Search for an element
   if (numbers.find(25) != numbers.end()) {
      cout << "25 is in the set." << endl;
   }

   // Print all elements
   cout << "Set contents: ";
   for (int num : numbers) {
      cout << num << " ";
   }
   return 0;
}