#include <iostream>
using namespace std;

class Add {

public:
   int operator()( int a, int b ) {
      return a + b;
   }
   double operator()( double a, double b ) {
      return a + b;
   }

};

void foo( Add& A ) {

   cout << A( 10, 20 ) << endl;

}


int main( ) {
   cout << "Jun09 - OOP345NEE" << endl;

   Add hoohoo;

   int x, y = 10, z = 20;

   x = hoohoo( y, z );



   return 0;
}