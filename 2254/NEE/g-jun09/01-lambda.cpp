#include <iostream>
using namespace std;
auto main( ) -> int {
   cout << "Jun09 - OOP345NEE" << endl;
   int times = 10;
   int ref;

   auto prnLamda =
   [=,&ref]( ) {
   for ( int i = 0; i < times; i++ )
      cout << "lambda" << endl;
   };



   return 0;
}