#include <iostream>
using namespace std;
class IntValidation {
public:
   virtual bool operator()( int )const = 0;
};

class NoValidation :public IntValidation {
public:
   bool operator()( int val )const {
      return true;
   }
};

class AdultValidation :public IntValidation {
public:
   bool operator()( int age )const {
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
};

class NoOfStdValidation :public IntValidation {
public:
   bool operator()( int num )const {
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
};






int getint(const  IntValidation& valid = NoValidation() ) {
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
         else if ( valid( num ) ) {
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
   age = getint( AdultValidation() );
   cout << "Number of students\n> ";
   noOfstd = getint( NoOfStdValidation() );
   cout << "Enter a number\n> ";
   aNumber = getint( );
   cout << "Number is: " << aNumber << endl;

   return 0;
}