#include <iostream>
#include "Stack.h"
using namespace std;
using namespace seneca;
int main( ) {
   Stack<double> S;
   for ( int i = 10; i < 100; i += 10 ) {
      S.push( i+0.01 );
   }
   for ( int j = 0; j < 8; j++ ) {
      cout << S.pop( ) << endl;
   }
   return 0;
}