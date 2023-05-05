#include <iostream>
using namespace std;
typedef unsigned int* uintptr;
typedef unsigned int uint;

// typedef makes life easier:
typedef const unsigned long long int* cullint_ptr;
typedef unsigned long long int ullint;
typedef unsigned long long int& ullint_ref;



//#define uintptr unsigned int* // will not work for line 7 since q becomes just an int 
int main() {
   uintptr p, q;
   uint ui = 20u;

   p = &ui;
   q = &ui;
   cout << *p << endl;
   cout << *q << endl;

   const unsigned long long int* lp, lq = 10, lr = 20; // only the first one is a pointer
   ullint ci = 20;;
   cullint_ptr a, b, c; // all pointers
   ullint_ref rc = ci;

   rc = 30;

   a = &ci;
   b = &ci;
   c = &ci;

   lp = &ci;

   cout << *a << "," << *b << "," << *c << "," << *lp << "," << lq << "," << lr << endl;

   return 0;
}