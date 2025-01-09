#include <iostream>
#include "Array.h"
using namespace std;
using namespace seneca;
int main( ) {
   Array<double> I( 10 );
   size_t i;
   double val;
   const double* p = (const double*)I;
   for ( i = 0, val = 10; i < 12; val += 5.5, i++ ) {
      I[i] = val;
   }
   cout << I << endl;
   cout << *p << endl;
   return 0;
}
