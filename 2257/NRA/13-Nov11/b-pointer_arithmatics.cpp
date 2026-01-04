#include <iostream>
using namespace std;

int main() {
   int numbers[] = { 10, 20, 30, 40, 50 };  // Array of 5 integers
   int size = 5;
   int* start = numbers;                    // Pointer to first element

   int sum = 0;
   for (int i = 0; i < size; ++i) {
      sum += *(start + i);                 // Access via offset
//      sum += *(numbers + i);                 // Access via offset
   }

   cout << "Array elements via pointer offsets:" << endl;
   for (int i = 0; i < size; ++i) {
      cout << "numbers[" << i << "] = " << *(start + i)
         << " (at address " << (start + i) << ")" << endl;
   }
   cout << "Sum: " << sum << endl;

   cout << "Array elements via pointer offsets:" << endl;
   for (int i = 0; i < size; ++i) {
      cout << "numbers[" << i << "] = " << *(start + i)
         << " (at address " << reinterpret_cast<unsigned long long int>((start + i)) << ")" << endl;
   }
   cout << "Sum: " << sum << endl;


   // Alternative: Increment pointer itself
   int* ptr = numbers;
   sum = 0;
   for (int i = 0; i < size; ++i) {
      sum += *ptr;
      cout << "numbers[" << i << "] = " << ptr[0] << " or " << *ptr<< endl;
      ++ptr;  // Move to next element
   }
   cout << "Sum via increment: " << sum << endl;

   return 0;
}