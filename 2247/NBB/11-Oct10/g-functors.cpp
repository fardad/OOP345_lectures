#include <iostream>
using namespace std;
class ValidInt {
protected:
   string message;
public:
   ValidInt(string theMessage ):message(theMessage ){ }
   virtual bool operator()( int value) = 0
};

int getint( ValidInt& valid ) {
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
         //         else if ( (*valid)(num) ) {  C syntax
         else if ( valid( num ) ) { // C++ syntax
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

class ValidAge :public ValidInt {
public:
   ValidAge():ValidInt("Invalid Age" ){ }
   bool  operator()( int value ) {
      bool res = true;
      if ( value <= 18 ) {
         cout << message << endl;
         res = false;
      }
      return res;
   }
};


int main( ) {
   ValidAge vage;
   getint( vage );

   return 0;
}