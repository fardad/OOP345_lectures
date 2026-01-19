#include <iostream>
using namespace std;

class Addition {
   size_t m_noOfCalls{};
public:
   int operator()( int a, int b ) {
      m_noOfCalls++;
      return a + b;
   }
   double operator()( double a, double b ) {
      m_noOfCalls++;
      return a + b;
   }
   size_t numberOfCalls( )const {
      return m_noOfCalls;
   }
};


int main( ) {
   Addition add;
   int x, y= 10, z=20;
   x = add( y, z );
   x = add( y, z );
   x = add( y, z );
   x = add( y, z );
   x = add( y, z );
   cout << "x is " << x << endl;
   cout << "add is called " << add.numberOfCalls( ) << " times" << endl;
   
   return 0;
}
