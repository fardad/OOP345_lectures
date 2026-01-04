// typedef.cpp
#include <iostream>
using namespace std;

typedef const int constInt; // alias
typedef int* intPtr; // alias for integer pointer

using IntAlias = int;       // modern alias that came with C++

int main() {
   int val = 20;
   int* a = &val,  // pointer 
        b = 120;   // integer
   intPtr P = &val,
      q = &b;


   constInt x = 5;
   IntAlias y = 10;
   cout << x << ", " << y << endl;
   return 0;
}