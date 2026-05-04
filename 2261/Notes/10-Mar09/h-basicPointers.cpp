#include <iostream>
using namespace std;

int main() {
   int value = 42;      // A simple integer variable
   int* ptr = &value;   // ptr holds the address of value

   cout << "Original value: " << value << endl;
   cout << "Address of value: " << &value << endl;
   cout << "Value via pointer: " << *ptr << endl;
   cout << "Address stored in ptr: " << ptr << endl;

   *ptr = 100;          // Modify via pointer
   cout << "Modified value: " << value << endl;

   return 0;
}