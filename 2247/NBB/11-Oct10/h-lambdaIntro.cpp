#include <iostream>
using namespace std;
int getint( bool (*valid)(int) ) {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if ( cin.fail( ) ) {
         cin.clear( );
         cout << "Unreadable integer, try again...\n> ";
      }
      else {
         if ( cin.peek( ) != '\n' ) {
            cout << "Please only enter an integer...\n> ";
         }
         else if ( valid( num ) ) {
            done = true;
         }
         else {
            cout << ", try again\n> ";
         }
      }
      cin.ignore( 100000, '\n' );
   } while ( !done );
   return num;
}
int main( ) {
   auto add = []( int a, int b ) -> int { return a + b; };
   cout << add( 5, 10 ) << endl;
   cout << []( double a, double b )->double {return a + b; }(200, 400) << endl;

   int age = getint(
      []( int num )->bool {
         bool ret = false;
         if ( num < 18 ) {
            cout << "No Children allowed!";
         }
         else if ( num > 65 ) {
            cout << "No Seniors please...";
         }
         else {
            ret = true;
         }
         return ret;
      }
   );

   return 0;
}
