
#include <iostream>
using namespace std;
bool isAdult( int num ) {
   return num >= 18 && num <= 65;
}
int getint( ) {
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
         else if ( isAdult( num ) ) {
            done = true;
         }
         else {
            cout << "no children or seniors...\n> ";
         }
      }
      cin.ignore( 100000, '\n' );
   } while ( !done );
   return num;
}


int main( void ) {
   int val;
   cout << "Enter an integer\n> ";
   val = getint( );

   return 0;
}