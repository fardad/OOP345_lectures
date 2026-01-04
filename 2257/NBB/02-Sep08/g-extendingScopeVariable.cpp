// only C++ 17
#include <iostream>
using namespace std;

int main( ) {
   int i;
   cout << "Enter i: ";
   cin >> i;

   if ( int j = i % 10; j < 5 ) {
      int k = j * 10;// k dies at line 13
      i -= j;   // round down
   }
   else {
      i += 10 - j; // round up
   }
   cout << i << endl;

   cout << "Enter i: ";
   cin >> i;
   switch ( int j = i % 10; j / 5 ) {
   case 0: i -= j; break;     // round down
   case 1: i += 10 - j; break; // round up
   }
   cout << i << endl;
}
