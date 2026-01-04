#include <iostream>
using namespace std;
typedef unsigned char Age;
typedef unsigned long long int* ulliPtr;
typedef int* iptr;

using intPtr = int*;

int main() {
   int val=20;
   int* a = &val,
      b = val;
   iptr p = &val,
      q = &b;
   cout << "OOP345NRA 01-Sep09" << endl;
   return 0;
}