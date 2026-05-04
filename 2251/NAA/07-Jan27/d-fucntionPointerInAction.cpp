#include <iostream>
using namespace std;
auto isAdult( int num ) -> bool {
   return num >= 18;
}

auto validNoOfStudents( int num ) -> bool {
   return num >= 10 && num <= 35;
}

auto getInt( auto (*isValid)(int)-> bool = nullptr ) -> int;

auto main( ) -> int {
   cout << "OOP345NAA - Jan 27" << endl;
   cout << "Enter Age:\n> ";
   int num = getInt( isAdult );
   cout << "You entered " << num << endl;
   cout << "Enter Number of students:\n> ";
   num = getInt( validNoOfStudents );
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
         else if ( isValid == nullptr || isValid( num ) ) {
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