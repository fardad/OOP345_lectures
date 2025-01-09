#include <iostream>
#include "Stack.h"
using namespace std;
using namespace seneca;
int main( ) {
   char str[3][10] = { "One","Two", "Three" };
   Stack<const char*> S;
   S.push( str[0] );
   S.push( str[1] );
   S.push( str[2] );
   for ( int i = 0; i < 3; i++ ) str[i][0] = 'X';
   while(!S.isEmpty ()){
      cout << S.pop() << " ";
   }
   cout << endl;
   return 0;
}