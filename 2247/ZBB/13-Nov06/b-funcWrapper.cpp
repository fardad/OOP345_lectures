/*
The <functional> library in C++ includes a class template called
std::unction, which acts as a general-purpose, type-erased
wrapper for any callable entity (e.g., functions, lambda expressions
, or function objects). This wrapper can be used to store
and invoke functions with a specific signature.
*/

#include <iostream>
#include <functional> // Include the <functional> header
using namespace std;

// A simple function to be wrapped
void sayHello( ) {
   cout << "Hello, World!" << endl;
}

// Another function to demonstrate taking an argument
int add( int a, int b ) {
   return a + b;
}

int main( ) {
   // Create a function wrapper for a void function with no parameters
   function<void( )> funcWrapper1 = sayHello;
   funcWrapper1( ); // Output: Hello, World!

   // Create a function wrapper for a function that takes two ints and returns an int
   function<int( int, int )> funcWrapper2 = add;
   int result = funcWrapper2( 5, 3 ); // Calls add(5, 3)
   cout << "Result of add(5, 3): " << result << endl; // Output: Result of add(5, 3): 8

   return 0;
}
