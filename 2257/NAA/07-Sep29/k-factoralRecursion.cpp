// file: recursion.cpp
#include <iostream>
using namespace std;

unsigned factorial(unsigned x) {
   return (x > 2u) ? x * factorial(x - 1) : x;
}

int main() {
   cout << "4! = " << factorial(4) << endl;
   return 0;
}