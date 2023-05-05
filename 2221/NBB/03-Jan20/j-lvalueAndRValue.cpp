#include <iostream>
using namespace std;

double tax = 0.7;

int value() {
   return 10;
}

double& taxValue() {
   return tax;
}

void foo(int& a) {
   a = 234;
}
int main() {
   int i;
   int* p;
   i = 6;
   double t;
   p = &i;
   //p = &76;  requires an lvalue
   // value() = 20;
   taxValue() = .234;
   double* ptr = &taxValue(); // ok because taxValue is an lvalue
   foo(i);
   //foo(123); not ok requires an lvalue;
   return 0;
}

