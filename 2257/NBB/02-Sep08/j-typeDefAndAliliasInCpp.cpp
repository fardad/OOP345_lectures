
#include <iostream>

struct Student_Rec {
   int stno;
};
// these come from C
typedef struct Student_Rec Student;
typedef unsigned long long int* ulliptr;
typedef int* intptr;

// C++ version

using cppIntPtr = int*;

int main( ) {
   unsigned long long int* ptr;
   ulliptr ptr2;
   Student S;
   int val = 10;
   int* a = &val, // pointer
      b = val; // just an integer

   intptr p = &val,
      q = &b;
   return 0;
}