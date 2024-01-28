#include <iostream>
using namespace std;

class Add {
   size_t m_noOfCalls{};
public:
   int operator()( int num1, int num2 ) {
      m_noOfCalls++;
      return num1 + num2;
   }
   operator size_t( )const {
      return m_noOfCalls;
   }
};

int main( ){
   Add add;
   int a = 10, b = 20, c;
   cout << "08-Oct06 OOP345 NBB" << endl;
   c = add( a, b );
   cout << c << endl;
   a = add( c, b );
   cout << a << endl;
   cout << size_t( add ) << " times called!" << endl;
   return 0;
}

