#include <iostream>
#include "Array.h"
using namespace std;
using namespace seneca;
int main( ) {
   Array<double> I( 10 );
   Array<char> C( 10 );
   int j;
   double i;
   for ( i = 10, j = 0; j < 12; i += 10.2, j++ ) {
      I[j] = i;
   }
   cout << I << endl;

   for ( j = 0; j < 20; j++ ) {
      C[j] = 'A' + j;
   }
   cout << C << endl;
}