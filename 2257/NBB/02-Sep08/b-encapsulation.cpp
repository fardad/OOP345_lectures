// encapsulation.cpp
#include <iostream>
using namespace std;

class BankAccount {
   double balance; // private data
public:
   BankAccount( double b = 0 ) : balance( b ) { }
   void deposit( double amt ) { balance += amt; }
   void withdraw( double amt ) { if ( amt <= balance ) balance -= amt; }
   void display( ) const { cout << "Balance: $" << balance << endl; }
};

int main( ) {
   BankAccount acct( 100 );
   acct.deposit( 50 );
   acct.withdraw( 30 );
   acct.display( ); // Balance: $120
}