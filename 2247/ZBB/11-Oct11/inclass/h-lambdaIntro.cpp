#include <iostream>
using namespace std;



int main( ) {
   int val = 300;
   auto add = []( int n1, int n2 )->int {
      int val = n1 + n2; // nothing to do with val in main
      return val;
   };
   cout << "val before add: " << val << endl;
   val = add( 10, 20 );
   cout << "val is: " << val << endl;

   return 0;
}