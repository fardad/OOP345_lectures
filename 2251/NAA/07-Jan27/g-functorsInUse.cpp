#include <iostream>
#include <string>
using namespace std;
class IntValidation {
protected:
   size_t m_noOfValidations{};
public:
   virtual bool operator()( int val, string& errMes ) = 0;
   size_t noOfCalls( )const {
      return m_noOfValidations;
   }
};

class isAdult :public IntValidation {
public:
   virtual bool operator()( int val, string& errMes ) {
      bool ok = false;
      if ( val >= 18 && val <= 64 ) {
         ok = true;
      }
      else {
         errMes = "Enter values between 18 and 64\n> ";
      }
      return ok;
   }
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