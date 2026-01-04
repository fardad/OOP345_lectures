/*

C++ has a built-in hierarchy under <exception>:

logic_error – programmer mistakes
out_of_range, invalid_argument, domain_error
runtime_error – issues at runtime
range_error, overflow_error, underflow_error
bad_alloc – failed new allocation
bad_cast – invalid dynamic_cast

*/

// file: bad_alloc_example.cpp
#include <iostream>
#include <new>
#include <cstring>
using namespace std;

int main() {
   char* p = nullptr;
   const char* s = "Hello Error Handling!";

   try {
      p = new char[strlen(s) + 1]; // may throw bad_alloc
      strcpy(p, s);
      cout << "Allocated: " << p << endl;
      delete[] p;
   }
   catch (bad_alloc&) {
      cout << "Insufficient memory" << endl;
   }
   catch (exception& e) {
      cout << "Standard exception: " << e.what() << endl;
   }

   return 0;
}