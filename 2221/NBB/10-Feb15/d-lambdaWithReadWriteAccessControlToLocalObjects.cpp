#include <iostream>
using namespace std;
int main() {
   int a = 10;
   int i = 5;

   auto addI2A = [&](int i) { return a += i; };
   auto sub4 = [](int i) { return i - 4; };
   auto showA = [&]() { cout << "a: " << a << endl; };

   // calls on the lambda expressions
   showA();
   cout << addI2A(10) << endl;
   showA();
   cout << sub4(10) << endl;
   [=](char ch) {
      for (int i = 0; i < a; i++) cout << ch;
      cout << endl;
   }('*');
   
   showA();
   [&](char ch) {
      for (; i < 10; i++) cout << ch;
      cout << endl;
   }('*');
   
   cout << "i: " << i << " a: " << a << endl;
   [&i, a](char ch) {
      for (; i < a; i++) cout << ch;
      cout << endl;
   }('*');
   
   cout << "i: " << i << " a: " << a << endl;
   [a, &i](char ch) {
      for (i = 0; i < a - 5; i++) cout << ch;
      cout << endl;
   }('*');
   
   cout << "i: " << i << " a: " << a << endl;
   
   [&, a](char ch) {
      for (i = 0; i < a; i++) cout << ch;
      cout << endl;
   }('*');
   
   cout << "i: " << i << " a: " << a << endl;
   
   [=, &i](char ch) {
      for (i = 0; i < a - 5; i++) cout << ch;
      cout << endl;
   }('*');
   cout << "i: " << i << " a: " << a << endl;

   return 0;
}