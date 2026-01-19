#include <iostream>
using namespace std;
int main( ) {

   auto greetings = []( ) { cout << "hello!" << endl; };

   auto repeat = []( int num, char ch ) {
      for ( int i = 0; i < num; i++ ) {
         cout << ch;
      }
      cout << endl;
      };

   greetings( );

   repeat( 10, 'A' );

   return 0;
}