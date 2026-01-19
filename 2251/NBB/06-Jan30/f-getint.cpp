#include <iostream>
using namespace std;
auto isAdult( int num ) -> bool {
   return num >= 18 && num <= 65;
}
auto validNoOfStudents( int num ) -> bool {
   return num >= 10 && num <= 35;
}
auto main( ) -> int {
   int age = getInt( );
   cout << "age: " << age << endl;
   return 0;
}
auto getInt( ) -> int {
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
         else if ( isAdult( num ) ) {
            done = true;
         }
         else {
            cout << "No children or Seniors permitted...\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}
