#include <iostream>
#include "Array.h"
using namespace std;
using namespace seneca;
int main( ) {
   IntArray I(10);
   int j, i;
   for ( i = 10, j=0; j<12; i+=10, j++ ) {
      I[j] = i;
   }
   cout << I << endl;
}