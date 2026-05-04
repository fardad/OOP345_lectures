#include <iostream>
#include "Record.h"
using namespace std;

Record print( Record T ) {
   Record S = "S in print";
   S = T;
   cout << "Printing: " <<  T << endl;
   return S;
}

int main( ) {
  // clog.setstate( ios::failbit );
   Record R( "OOP345 NEE" );
   Record S = "Some data";
   cout << "R: " << R << endl;
   cout << "S: " << S << endl;
   S = move( R );
   cout << "R: " << R << endl;
   cout << "S: " << S << endl;
   print( move( S ) );
   print( "This does not need move" );

   return 0;
}