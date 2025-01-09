#include <iostream>
using namespace std;

int getint( bool (*valid)(int) = nullptr ) {
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
         else if ( valid == nullptr || valid( num ) ) {
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
   int age;
   cout << "Enter age\n> ";
   age = getint(
      []( int age )->bool {
         bool ret = false;
         if ( age < 18 ) {
            cout << "No Children allowed!";
         }
         else if ( age > 65 ) {
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