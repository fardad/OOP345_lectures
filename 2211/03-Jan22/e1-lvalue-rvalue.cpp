#include <iostream>
using namespace std;

double tax = .7;

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
   // p = &76;  // rvalue, cant be done
   i = value();
   // value() = 25; // rvalue is turned, can't be done; 
   t = taxValue();  // no problem
   cout << t << endl;

   taxValue() = .15; // returns lvalue, can be done.

   cout << tax << endl;
   double* ptr = &taxValue(); // ok too, since lvalue is returned. 
   cout << *ptr << endl;

   foo(i);
   cout << i << endl;

   //foo(500); // not possible, foo requires an lvalue


   return 0;
}
