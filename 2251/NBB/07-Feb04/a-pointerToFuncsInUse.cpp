#include <iostream>
using namespace std;

bool isAdult( int num )  {
   bool ok = (num >= 18 && num <= 65);
   if (!ok) {
      cout << "No children or seniors please!";
   }
   return ok;
}
bool validNoOfStudents( int num )  {
   bool ok = num >= 10 && num <= 35;
   if ( !ok ) {
      cout << "Invalid number of students!";
   }
   return ok;
}

int getInt( bool (*isValid)(int) = nullptr);
int main( ) {
   cout << "07 - Feb04 - OOP345NBB" << endl;
   cout << "Age?\n> ";
   int age = getInt( isAdult );
  
   cout << "Number of students\n> ";
   int noOst = getInt( validNoOfStudents );


   cout << "A number\n> ";
   int justAnInt = getInt( );

   return 0;
}
int getInt(bool (*isValid)(int)  ) {
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
         else if (isValid == nullptr || isValid( num ) ) {
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
