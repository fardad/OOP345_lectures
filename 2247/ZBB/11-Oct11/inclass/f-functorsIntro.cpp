#include <iostream>
using namespace std;
class Add {
public:
   int func( int num1, int num2 ) {
      return num1 + num2;
   }
   int operator()( int num1, int num2 ) {
      return num1 + num2;
   }
   double operator()( double num1, double num2 ) {
      return num1 + num2;
   }
};



int main( ) {
   Add add;
   double dval;
   int value = add.func( 10, 20 );
   cout << "value is: " << value << endl;
   value = add( 40, 50 );
   cout << "value is: " << value << endl;
   dval = add( 11.22, 33.44 );
   cout << "Double value is: " << dval << endl;
   return 0;
}