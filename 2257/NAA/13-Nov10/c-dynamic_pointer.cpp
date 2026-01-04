#include <iostream>
using namespace std;

int main() {
   int size;
   cout << "Enter array size: ";
   cin >> size;

   int* dynamicArray = new int[size];  // Allocate dynamic array

   cout << "Enter " << size << " integers:" << endl;
   for (int i = 0; i < size; ++i) {
      cin >> dynamicArray[i];          // Fill via pointer (array notation)
   }

   // Find maximum using pointer traversal
   int maxValue = *dynamicArray;        // Start with first element
   int* ptr = dynamicArray + 1;         // Skip first
   for (int i = 1; i < size; ++i) {
      if (*ptr > maxValue) {
         maxValue = *ptr;
      }
      ++ptr;
   }

   cout << "Maximum value: " << maxValue << endl;

   // Cleanup
   delete[] dynamicArray;
   dynamicArray = nullptr;              // Avoid dangling pointer

   cout << "Memory freed successfully." << endl;

   return 0;
}