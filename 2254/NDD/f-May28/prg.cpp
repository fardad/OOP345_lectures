#include <iostream>
using namespace std;
int main( ) {
   int a = 10;
   int i = 5;

   //[&] everything by reference
   auto addI2A = [&]( int i ) { return a += i; };
   auto sub4 = []( int i ) { return i - 4; };
   auto showA = [&]( ) { cout << "a: " << a << endl; };

   showA( );
   cout << addI2A( 10 ) << endl;
   showA( );
   cout << sub4( 10 ) << endl;

   [=]( char ch ) {
      for ( int i = 0; i < a; i++ ) cout << ch;
      cout << endl;
      }('*');
   showA( );

   [&]( char ch ) {
      for ( ; i < 10; i++ ) cout << ch;
      cout << endl;
      }('*');
   cout << "i: " << i << " a: " << a << endl;

   //[&i, a] i by ref, a by val
   auto refAnVal = [&i, a]( char ch ) {
      for ( ; i < a; i++ ) cout << ch;
      cout << endl;
      };
   refAnVal( '*' );
   cout << "i: " << i << " a: " << a << endl;


   [a, &i]( char ch ) {
      for ( i = 0; i < a - 5; i++ ) cout << ch;
      cout << endl;
      }('*');
   cout << "i: " << i << " a: " << a << endl;


   //[&, a] everything by ref except a that is by val
   [&, a]( char ch ) {
      for ( i = 0; i < a; i++ ) cout << ch;
      cout << endl;
      }('*');
   cout << "i: " << i << " a: " << a << endl;

   //[=, &i] everything by val except i that is by ref
   [=, &i]( char ch ) {
      for ( i = 0; i < a - 5; i++ ) cout << ch;
      cout << endl;
      }('*');
   cout << "i: " << i << " a: " << a << endl;

   return 0;
}