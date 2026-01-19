#include <iostream>
using namespace std;

class Adding {  // functor or function objects
   size_t m_numberOfCalls{ };
public:
   int operator() ( int num1, int num2 ) {
      m_numberOfCalls++;
      return num1 + num2;
   }
   float operator() ( float num1, float num2 ) {
      m_numberOfCalls++;
      return num1 + num2;
   }
   double operator() ( double num1, doube num2 ) {
      m_numberOfCalls++;
      return num1 + num2;
   }
   size_t noOfCalls( )const {
      return m_numberOfCalls;
   }
};

int main( ) {
   Adding add;
   int a, b =20;
   cout << add.noOfCalls( ) << endl;
   a = add( b, 30 );
   cout << "add( b, 30 ): " << a <<  endl; 
   cout << add.noOfCalls( ) << endl;

   return 0;
}
