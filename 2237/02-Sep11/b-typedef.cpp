#include <iostream>
using namespace std;
int main() {
   typedef const unsigned long long int* culli_type;
   const unsigned long long int* numptr;
   culli_type a;
   typedef int* intptr;
   int* a, b;
   // a is int*
   // b is int
   intptr p, q;
   // p is int*
   // q is int*
   return 0;
}