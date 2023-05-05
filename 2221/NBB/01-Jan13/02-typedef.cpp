#include "module.h"
#include <iostream>
typedef int* intptr;
struct Student {
   int stno;
   char name[50];
};

typedef
struct {
   int empno;
   char name[50];
} Employee;


int main() {
   struct Student std;

   Employee A;


   intptr a, b;

   return 0;
}