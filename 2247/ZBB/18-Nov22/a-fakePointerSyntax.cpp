// lecture video at: https://youtu.be/N_baE60Yu-o

#include <iostream>
using namespace std;
#include "pointer.h"
int main( ) {
   double d = 123.456;
   double Pointer ptr = AddressOf d;
   cout << TargetOf ptr << endl;
   TargetOf ptr = 345.678;
   cout << d << endl;
   return 0;
}