#include <iostream>

using namespace std;
int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   int x = 42;
   int* p = &x;     // pointer to int

   cout << "Value of x: " << x << endl;
   cout << "Pointer p points to: " << *p << endl; // dereference
   return 0;
}