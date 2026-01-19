#include <iostream>
#include "Record.h"
using namespace std;

Record print( Record rec ) {
   Record S = "S in print";
   S = rec;
   cout << "Printing: " << rec << endl;
   return S;
}


int main( ) {
   Record R = "May28 - OOP345 NDD";
   Record S = "Some value";
   R = print( "Something" ); // print(Record rec = "something");
   cout << R << endl;
   cout << "S: " << S << endl;
   Record T( move( S ) );
   cout << "S: " << S << endl;
   cout << "T: " << T << endl;
   cout << "R: " << R << endl;
   T = move( R );
   cout << "T: " << T << endl;
   cout << "R: " << R << endl;
   return 0;
}