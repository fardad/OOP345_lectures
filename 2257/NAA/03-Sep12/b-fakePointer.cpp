#include <iostream>
#include "pointer.h"
using namespace std;
int main() {
   cout << "03-Sep12 OOP345 NAA" << endl;
   int var;
   int Pointer ptr;
   ptr = AddressOf var;
   TargetOf ptr = 2345;
   cout << var << endl;
   return 0;
}