
#include <iostream>
using namespace std;

union Pack {
   double dval;
   char cval[8];
};

struct Product {
   union {
      long long UPC;
      char serial[4];
   } key;


};

int main() {
   Pack P;
   P.dval = 123.45;
   cout << P.dval << endl;
   for (int i = 0; i < 7; i++) {
      P.cval[i] = 'A' + i;
   }
   P.cval[7] = 0;
   cout << P.cval << endl;
   cout << P.dval << endl;
   cout << reinterpret_cast<unsigned long long>(&P.dval) << ", " << reinterpret_cast<unsigned long long>(P.cval) << endl;
   return 0;
}