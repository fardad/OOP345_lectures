#include <iostream>
#include "pointer.h"
using namespace std;
int main() {
   cout << "03-SEP11 OOP345 NBB" << endl;
   int var = 2345;
   int Pointer ptr;
   ptr = AddressOf var;
   cout << TargetOf ptr << endl;
   cout << ptr << endl;
   cout << reinterpret_cast<unsigned long long>(ptr) << endl;
   return 0;
}