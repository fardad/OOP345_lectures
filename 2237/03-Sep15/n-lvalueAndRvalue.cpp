#include <iostream>
using namespace std;
double tax = 0.7;
int value( ) {
   return 10;
}
double& taxValue( ) {
   return tax;
}
int main( ) {
   int i;
   int* p;
   i = 6;
   p = &i;
   i = value( );
   cout << taxValue( ) << endl;
   taxValue( ) = 0.13;
   cout << tax << endl;
   cout << taxValue( ) << endl;
}