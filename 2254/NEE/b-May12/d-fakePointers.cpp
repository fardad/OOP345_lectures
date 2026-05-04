#include <iostream>
#include "pointers.h"
using namespace std;
typedef int* intptr;

typedef struct {
   char name[41];
   unsigned Stno;
} Student; // common in C to make a struct a type without reusing struct keyword.


int main( ) {
   int* a, b, c;  // b and c are not pointers
   intptr q, r, s; // they are all pointers

   return 0;
}