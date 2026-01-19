#include <iostream>
using namespace std;

auto isAdult( int num ) -> bool {
   return num >= 18 && num <= 65;
}
auto validNoOfStudents( int num ) -> bool {
   return num >= 10 && num <= 35;
}
auto getInt( auto (*isValid)(int)->bool ) -> int;
auto main( ) -> int {

   cout << "OOP345NEE - May26 - Functions" << endl;
   cout << "Enter your age: ";
   int age = getInt( isAdult );
   cout << "age: " << age << endl;
   cout << "Enter number of students: ";
   int stno = getInt( validNoOfStudents );
   cout << "no Of students: " << stno << endl;
   return 0;
}
auto getInt(  auto (*isValid)(int)->bool  ) -> int {
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
         else if ( isValid( num ) ) {
            done = true;
         }
         else {
            cout << "Invalid Value...\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}

