// static_dynamic.cpp
#include <iostream>
using namespace std;

int main() {
   int a = 10;            // static allocation (stack)
   int* b = new int(20);  // dynamic allocation (heap)

   cout << a << ", " << *b << endl;

   delete b; // must free heap memory
}