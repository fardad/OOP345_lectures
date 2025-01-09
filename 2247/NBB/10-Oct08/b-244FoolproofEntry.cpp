#include <iostream>
using namespace std;
//int getint(){
auto isAdult( int num ) -> bool {
   return num >= 18 && num <= 65;
}
auto validNoOfStudents( int num ) -> bool {
   return num >= 10 && num <= 35;
}
auto getint( ) -> int {
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
         else if(isAdult(num)){
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