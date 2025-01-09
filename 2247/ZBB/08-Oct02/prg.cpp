#include <iostream>
#include "Array.h"
using namespace std;
using namespace seneca;
void display( Array<double>& A ) {
   for ( size_t i = 0; i < A.size( ); i++ ) {
      cout << A[i] << " ";
   }
   cout << endl;
}
int main( ) {
   Array<double> I( 10 );
   size_t i;
   double val;
   const double* p = (const double*)I;
   for ( i = 0, val = 10; i < 12; val += 5.5, i++ ) {
      I[i] = val;
   }
   display( I );
   return 0;
}
