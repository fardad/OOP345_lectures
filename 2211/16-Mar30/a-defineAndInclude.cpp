#include <iostream>
using namespace std;


#ifdef pointer
#undef pointer
#endif 
#define pointer *


#define targetOf *
#define adderssOf &

int main() {
   int a;
   int pointer p;
   p = adderssOf a;
   targetOf p = 123;
   cout << a << endl;
#include "hoohoo.hee"
#include "whatever.w"
   return 0;
}