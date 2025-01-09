#include <iostream>
using namespace std;
int value( ) {
   return 10;
}
double& taxValue( ) {
   static double tax = 0.7;
   return tax;
}
void WhichVal( int& lv ) {
   cout << "lv: " << lv << endl;
   lv++;
}
void WhichVal( int&& rv ) {
   cout << "rv: " << rv << endl;
   rv += 10;
}

int main( ) {
   int i;
   i = value( );
   cout << value( ) << endl;
   cout << taxValue( ) << endl;
   taxValue( ) = 0.13;
   cout << taxValue( ) << endl;
   WhichVal( i );
   cout << i << endl;
   WhichVal( 100 );
   WhichVal( move( i ) );
   cout << i << endl;
   return 0;
}