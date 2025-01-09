
#include <iostream>
#include <functional> 
using namespace std;


int main( ) {
   double a, b=1.1, c=2.2, d=3.3;
   multiplies<double> mul;
   a = b * c * d;
   cout << mul(mul( a,b ),c) << endl;

   return 0;
}
