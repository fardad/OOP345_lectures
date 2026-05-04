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


