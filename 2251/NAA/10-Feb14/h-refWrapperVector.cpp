
#include <iostream>
#include <functional> 
#include <vector>
using namespace std;
/*

The vector refVector holds references to x, y, and z using std::reference_wrapper<int>.

Modifying the values through refVector directly affects the original variables because
the vector contains references, not copies.

Key Methods of std::reference_wrapper
get(): Returns the underlying reference.

Implicit conversion: std::reference_wrapper can often be used directly in places
where a reference is expected, thanks to implicit conversion to T&.

*/


int main( ) {
   int x = 5;
   int y = 10;
   int z = 15;

   // Create a vector of reference wrappers
   std::vector<std::reference_wrapper<int>> refVector = { x, y, z };

   // Modify the original variables through the vector
   for ( auto& ref : refVector ) {
      ref.get( ) += 10; // Increment each referenced value by 10
   }

   // Print the modified values of x, y, and z
   std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl; // Output: x: 15, y: 20, z: 25

   return 0;
}
