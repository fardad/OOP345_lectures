
#include <iostream>
#include <functional> // Include the <functional> header
using namespace std;

// A functor (function object)
struct Multiply {
   int operator()( int a, int b ) const {
      return a * b;
   }
};

int main( ) {
   // Create a function that wraps a functor
   function<int( int, int )> funcWrapper = Multiply( );

   // Call the wrapped functor
   cout << "Multiplication result: " << funcWrapper( 3, 7 ) << endl; // Output: Multiplication result: 21

   return 0;
}
