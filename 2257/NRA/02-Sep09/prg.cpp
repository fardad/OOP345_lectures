// rvalue.cpp
#include <iostream>
using namespace std;

void print(const int& n) { cout << "lvalue: " << n << endl; }
void print(int&& n) { cout << "rvalue: " << n << endl; }

int main() {
   int x = 10;
   print(x);      // lvalue
   print(20);     // rvalue
   print(int(x));
   return 0;
}