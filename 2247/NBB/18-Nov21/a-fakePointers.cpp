#include <iostream>
#include "Pointer.h"
using namespace std;
int main( ) {
   int var;
   int Pointer p;
   p = AddressOf var;
   TargetOf p = 200;
   cout << TargetOf p << " <-> " << var << endl;
   return 0;
}