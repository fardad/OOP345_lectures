#include <iostream>
#include <string>
using namespace std;
bool isAdult( int num, string& err ) {
   bool res = true;
   if ( !(num >= 18 && num <= 65) ) {
      err = "No children or Seniors";
      res = false;
   }
   return res;
}
bool validNoOfStudents( int num, string& err ) {
   bool res = true;
   if ( !(num >= 10 && num <= 35) ) {
      err = "Invlid number of students";
      res = false;
   }
   return res;
}
int getInt( bool (*isValid)(int, string&) = nullptr );
int main( ) {
   cout << "08-Oct06 OOP345 NBB" << endl;
   cout << "Enter your age: ";
   int age = getInt( isAdult );
   cout << "age: " << age << endl;
   cout << "Enter the number of studets: ";
   int stno = getInt( validNoOfStudents );
   cout << stno << " students in class." << endl;
   return 0;
}
int getInt( bool (*isValid)(int, string&) ) {
   int num{};
   bool done = false;
   string errMes{};
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
         else if ( isValid == nullptr || isValid( num, errMes ) ) {
            done = true;
         }
         else {
            cout << errMes << "...\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}
