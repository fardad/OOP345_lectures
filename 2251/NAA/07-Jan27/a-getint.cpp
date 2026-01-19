#include <iostream>
using namespace std;
auto isAdult( int num ) -> bool {
   return num >= 18;
}

auto validNoOfStudents( int num ) -> bool {
   return num >= 10 && num <= 35;
}

auto getInt( ) -> int;

auto main( )->int {
   cout << "OOP345NAA - Jan 27" << endl;
   cout << "Number: ";
   int num = getInt( );
   cout << "You entered " << num << endl;
   return 0;
}

auto getInt( ) -> int {
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
         else if(isAdult(num)){
            done = true;
         }
         else {
            cout << "Only adults over 18 please...\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}