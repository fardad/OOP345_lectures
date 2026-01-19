#include <iostream>
using namespace std;

class Addition {
   size_t m_noOfCalls{};
public:
   int operator()( int n1, int n2 ) {
      m_noOfCalls++;
      return n1 + n2;
   }
   size_t numberOfCalls( )const {
      return m_noOfCalls;
   }
};


int main( ) {
   Addition add;

   int num, x = 10, y = 20;

   num = add( x, y );
   num = add( x, y );
   num = add( x, y );
   num = add( x, y );

   cout << "add is called " << add.numberOfCalls( ) << "time" << endl;

   return 0;
}