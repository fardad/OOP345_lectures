#include <iostream>
#include "Record.h"
using namespace std;

template<typename T1, typename T2>
auto add(T1 a,T2  b ) -> decltype(a+b){
   retur4n a + b;
}



auto print( Record rec )-> Record {
   Record S = "S in print";
   S = rec;
   cout << "Printing: " << rec << endl;
   return S;
}


auto main( )->int {
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