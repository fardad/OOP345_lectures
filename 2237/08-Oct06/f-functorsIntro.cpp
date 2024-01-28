#include <iostream>
#include <string>
using namespace std;
class IntValidation {
protected:
   int m_noOfValidations{};
public:
   virtual bool operator()( int val, string& errMes ) = 0;
};
int getInt( IntValidation& valid ) {
   int num{};
   bool done = false;
   string message = "";
   do {
      cin >> num;
      if ( cin.fail( ) ) {
         cin.clear( );
         cout << "Invlid integer, try again...\n> ";
      }
      else {
         if ( cin.peek( ) != '\n' ) {
            cout << "Only an integer...\n> ";
         }
         else if ( valid( num, message ) ) {
            done = true;
         }
         else {
            cout << message << "...\n> ";
         }
      }
      cin.ignore( 10000, '\n' );
   } while ( !done );
   return num;
}
int main( ) {
   return 0;
}