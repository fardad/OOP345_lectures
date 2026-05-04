#include <iostream>
using namespace std;

void add(int a, int b) {
   cout <<  a + b << endl;
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

int main(){
   cout << "OOP345 NBB - Feb 02" << endl;
   /*cout << reinterpret_cast<unsigned long long>(add) << endl;
   cout << reinterpret_cast<unsigned long long>(mul) << endl;
   cout << reinterpret_cast<unsigned long long>(dev) << endl;
   cout << reinterpret_cast<unsigned long long>(red) << endl;*/
   int* x;
   void (*funcptr)(int, int);
   funcptr = add;
   funcptr(40, 10);
   funcptr = mul;
   funcptr(40, 10);
   funcptr = dev;
   funcptr(40, 10);
   funcptr = red;
   funcptr(40, 10);

   return 0;
}

