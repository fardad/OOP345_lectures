#include <iostream>
using namespace std;
bool isAdult( int age ) {
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
bool validNoOfStudents( int num ) {
   bool ret = false;
   if ( num < 5 ) {
      cout << "Too few students to form a class";
   }
   else if ( num > 40 ) {
      cout << "Too many students, form a new class";
   }
   else {
      ret = true;
   }
   return ret;
}
int getint( bool (*valid)(int) =nullptr) {
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
   int age, noOfstd, aNumber;
   cout << "Enter age\n> ";
   age = getint( isAdult );// getint(bool (*valid)(int) = isAdult )
   cout << "Number of students\n> ";
   noOfstd = getint( validNoOfStudents );//getint(bool (*valid)(int) = validNoOfStudents ) 
   aNumber = getint( );

   return 0;
}