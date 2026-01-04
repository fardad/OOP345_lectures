// pointer.cpp
#include <iostream>
#include "pointer.h"
using namespace std;

int main() {
   int Pointer ptr;
   int var = 123;
   ptr = AddressOf var;
   cout << var << endl;
   cout << TargetOf ptr << endl;
   cout << ptr << endl;

   TargetOf ptr = 23456;
   cout << var << endl;

   return 0;
}