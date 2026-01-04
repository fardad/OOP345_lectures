// initializers.cpp
#include <iostream>
using namespace std;

int main() {
   int a[]{ 1, 2, 3 };
   int b[5]{ 1, 2, 3 }; // rest zero-initialized
   int c[5]{};        // all elements 0

   for (int e : a) cout << e; cout << "|" << endl;
   for (int e : b) cout << e; cout << "|" << endl;
   for (int e : c) cout << e; cout << "|" << endl;
   return 0;
}