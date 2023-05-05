#include <iostream>
using namespace std;

int add(int a, int b) { 
   return a + b;
}

int dvd(int a, int b) {
   return a / b;
}

int main() {
   int V;
   int (*funcPtr)(int, int);
   funcPtr = add;
   V = funcPtr(3, 4);
   cout << V << endl;
   funcPtr = dvd;
   V = funcPtr(4, 2);
   cout << V << endl;

   return 0;
}
