
/*
logic_error: Programmer mistakes 
out_of_range, invalid_argument, domain_error
runtime_error:
range_error, overflow_error, underflow_error
bad_alloc: when new fails
bad_cast: dynamic_cast


*/
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
   catch (const bad_alloc& e) {
      cout << "Insufficient memory: " << e.what() << endl;
   }
   catch (const exception& e) {
      cout << "Standard exception: " << e.what() << endl;
   }
   catch (...) {
      cout << "when it really hits the fan!!!" << endl;
   }

   return 0;
}