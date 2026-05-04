#include <iostream>
using namespace std;
void func( ) {
   static int i = 1;
   i++;
   cout << i;
}

int main( ) {
   cout << "OOP345 NEE May 07" << endl;
   for ( int j = 0; j < 3; j++ ) {
      func( );
   }
   cout << endl;
   return 0;
}

