#include <iostream>
using namespace std;

void add(int a, int b) {
   cout << a + b << endl;
}
void mul(int a, int b) {
   cout << a * b << endl;
}
void dev(int a, int b) {
   cout << a / b << endl;
}
void red(int a, int b) {
   cout << a - b << endl;
}

void rep(int val, int repeat) {
   for (int i = 0; i < repeat; i++) {
      cout << val << " ";
   }
   cout << endl;
}

int main() {
   cout << "OOP345 NBB - Feb06" << endl;
   /*cout << reinterpret_cast<unsigned long long>(add) << endl;
   cout << reinterpret_cast<unsigned long long>(mul) << endl;
   cout << reinterpret_cast<unsigned long long>(dev) << endl;
   cout << reinterpret_cast<unsigned long long>(red) << endl;*/
   int val;
   int* x = &val;

   *x = 123;// therefore val will be set to 234

 

   void (*funcptr)(int, int);// only a pointer to any logic accepting two ints and return nothing
   funcptr = add;
   funcptr(40, 10);
   funcptr = rep;
   funcptr(40, 10);


   return 0;
}
