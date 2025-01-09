/*
[capture_clause](parameter_list) -> return_type {
    // body of lambda
};

capture_clause: Specifies which outside variables are available
   for the lambda.
parameter_list: The parameters just like in a regular function.
return_type: Optional. If omitted, it's inferred from the
   return statements in the lambda.
body: The code to be executed when the lambda is invoked.

Let's break down the components:

1- Capture Clause: Determines how variables from the enclosing
   scope are captured for use inside the lambda.

   []: No variables are captured.
   [=]: Captures all used variables by value.
   [&]: Captures all used variables by reference.
   [x, &y]: Captures x by value and y by reference.

2- Parameter List: Just like regular function parameters.

3- Return Type: It's optional. If omitted, it's inferred
   from the return statements in the lambda.

4- Body: Contains the code that will be executed when
   the lambda is called.




*/

#include <iostream>
using namespace std;
int main( ) {
   int a = 10;
   int i = 5;

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

   [&, a]( char ch ) {
      for ( i = 0; i < a; i++ ) cout << ch;
      cout << endl;
      }('*');
   cout << "i: " << i << " a: " << a << endl;

   [=, &i]( char ch ) {
      for ( i = 0; i < a - 5; i++ ) cout << ch;
      cout << endl;
      }('*');
   cout << "i: " << i << " a: " << a << endl;

   return 0;
}