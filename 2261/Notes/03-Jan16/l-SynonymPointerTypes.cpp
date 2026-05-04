#include <iostream>

using namespace std;
int main() {
   typedef unsigned long long int ullint;
   ullint* p; // pointer to ullint

   // typedef unsigned long long int* ullint_ptr; using the C++ way below

   using ullint_ptr = unsigned long long int*;

   ullint_ptr p1, p2; // simpler than: unsigned long long int* p1, *p2;


   cout << "OOP345NBB - Jan 16" << endl;
   return 0;
}