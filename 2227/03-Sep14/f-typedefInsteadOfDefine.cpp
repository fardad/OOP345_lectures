#include <iostream>
using namespace std;

typedef int* intPtr;

int main() {
   intPtr   // this is a type now
      p,  // pointer
      q; // pointer
   int a = 10;
   p = &a;
   q = &a;
   cout << *p << " " << *q << endl;
   return 0;
}
