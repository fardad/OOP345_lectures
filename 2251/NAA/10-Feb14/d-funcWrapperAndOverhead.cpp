
#include <iostream>
#include <functional> // Include the <functional> header
using namespace std;
/*
Important Points to Remember
Overhead : std::function introduces some runtime overhead due to
its type - erased nature, so it may not be as fast as direct
calls to functions or lambdas.

Nullability : You can create an empty std::function object that
behaves like a null pointer.Always check if it is callable
using if (funcWrapper) before invoking it.
*/

int main( ) {
   std::function<void( )> emptyFunc;

   if ( emptyFunc ) {
      emptyFunc( ); // This won't be called, as emptyFunc is empty.
   }
   else {
      std::cout << "Function wrapper is empty." << std::endl; // Output: Function wrapper is empty.
   }
   return 0;
}