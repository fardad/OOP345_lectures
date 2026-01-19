#include <iostream>
using namespace std;


auto getInt( auto (*isValid)(int)-> bool ) -> int;

auto main( ) -> int {
   cout << "OOP345 NAA 08- Feb 03" << endl;
   cout << "Enter Age:\n> ";
   int num = getInt( []( int num ) { return num > 18; } );
   auto vNoStd = []( int noOfStd ) {
      return noOfStd >= 10 && noOfStd <= 45;
   };
   
   cout << "You entered " << num << endl;
   cout << "Enter Number of students:\n> ";
   num = getInt( vNoStd );
   cout << "You entered " << num << endl;
   return 0;
}

auto getInt( auto (*isValid)(int) ->bool ) -> int {
   int num{ };
   bool done{};
   do {
      cin >> num;
      if ( cin.fail( ) ) {
         cin.clear( );
         cout << "Invalid integer, try again...\n> ";
      }
      else {
         if ( cin.peek( ) != '\n' ) {
            cout << "Only an integer please...\n> ";
         }
         else if ( isValid( num ) ) {
            done = true;
         }
         else {
            cout << "Invalid Integer value...\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}