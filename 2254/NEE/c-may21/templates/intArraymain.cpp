#include <iostream>
#include "IntArray.h"
using namespace std;
using namespace seneca;
int main( ) {
   IntArray I(4);
   for ( int i = 0; i < 4; i++ ) {
      I[i] = (i + 1) * 10;
   }
   cout << I << endl;
   return 0;
}