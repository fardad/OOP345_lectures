#include <iostream>
using namespace std;


int main( ) {

   auto valid = []( int value )->bool { return value >= 0 && value <= 100; };

   if ( valid( 30 ) ) {
      cout << "30 is between 0 and 100" << endl;
   }


   return 0;
}
