#include <iostream>
using namespace std;

class Adding {
   size_t m_noOfOperations{};
public:
   int operator()( int n1, int n2 ) {
      m_noOfOperations++;
      return n1 + n2;
   }
   double operator()( double n1, double n2 ) {
      m_noOfOperations++;
      return n1 + n2;
   }
   size_t noOfOperations( )const {
      return m_noOfOperations;
   }
};


int getInt( bool (*isValid)(int) );

int main( ) {
   cout << "07 - Feb04 - OOP345NBB" << endl;
   int a, b = 20;
   Adding add;
   a = add( b, 30 );
   a = add( b, 30 );
   a = add( b, 30 );
   a = add( b, 30 );
   a = add( b, 30 );
   cout << a << endl;
   cout << "added " << add.noOfOperations( ) << " times!" << endl;
   return 0;
}

using namespace std;
class IntValidation {
protected:
   int m_noOfValidations{};
public:
   virtual bool operator()( int val, string& errMes ) = 0;
   int noOfValidations( )const {
      return m_noOfValidations;
   }
};

class ValidAge : public IntValidation {
public:
   virtual bool operator()( int val, string& errMes ) {
      bool ok;
      if ( (ok = val < 18 || val > 65) ) {
         errMes = "No children or seniors";
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