#include <iostream>
#include <memory>
using namespace std;

int main() {
   unique_ptr<int> ptr(new int(42));  // Exclusive ownership of int

   cout << "Value via unique_ptr: " << *ptr << endl;
   cout << "Address: " << ptr.get() << endl;

   *ptr = 100;  // Modify safely
   cout << "Modified value: " << *ptr << endl;

   // Scope ends: auto-delete, no leak
   return 0;
}