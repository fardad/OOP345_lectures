#include <iostream>
#include "Stack.h"
using namespace std;
using namespace seneca;
int main( ) {
   Stack<double> S;
   for ( int i = 10; i < 111; i += 10 ) {
      S.push( i + 0.1 );
   }
   for(int j=0;j<5;j++){
      cout << S.pop( ) << " ";
   }
   cout << endl;
   return 0;
}