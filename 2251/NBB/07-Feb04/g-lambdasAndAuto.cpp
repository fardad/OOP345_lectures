#include <iostream>
using namespace std;

int getInt( bool (*isValid)(int) );

int main( ) {
   cout << "07 - Feb04 - OOP345NBB" << endl;

   auto isPos = []( int val )->bool {
      bool ok = val >= 0;
      if ( !ok ) cout << "Only poisitive values";
      return ok;
      };


   cout << "Enter a value:\n> ";
   int num = getInt( isPos );

   return 0;
}

int getInt( bool (*isValid)(int) ) {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if ( cin.fail( ) ) {
         cin.clear( );
         cout << "Invlid integer, try again...\n> ";
      }
      else {
         if ( cin.peek( ) != '\n' ) {
            cout << "Only an integer number please...\n> ";
         }
         else if ( isValid == nullptr || isValid( num ) ) {
            done = true;
         }
         else {
            cout << "\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}