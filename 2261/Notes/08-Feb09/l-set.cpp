#include <iostream>
#include <set>
using namespace std;
int main() {
   cout << "OOP345 NBB - Feb 09" << endl;
   set<int> numbers = { 30, 10, 20 };  // Automatically sorted

   // Add elements
   numbers.insert(25);
   numbers.insert(10);              // Duplicate ignored

   // Search for an element
   auto oneAfterLast = numbers.end();
   auto no25 = numbers.find(25);
   if (no25 != oneAfterLast) {
      cout << *no25 << " is in the set." << endl;
   }

   // Print all elements
   cout << "Set contents: ";
   for (int num : numbers) {
      cout << num << " ";
   }
   return 0;
}
