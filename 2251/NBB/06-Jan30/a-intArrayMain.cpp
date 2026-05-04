#include <iostream>
#include "IntArray.h"
using namespace std;
using namespace seneca;
void display(const IntArray& I ) {
   cout << I << endl;
}
int main( ) {
   cout << "OOP345NBB - Jan 30" << endl;
   IntArray I(5);
   size_t i;
   for ( i = 0; i < 8; i++ ) {
      I[i] = (i + 1) * 10;
   }
   display( I );
   return 0;
}