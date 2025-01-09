
#include <iostream>
#include <functional> 
using namespace std;

/*
In the <functional> library in C++, std::ref and std::cref are helper
functions used to create reference wrappers for objects. These are
especially useful when you want to pass objects by reference to
functions or store references in containers, while ensuring that
copies are not made. Here’s how they work:

std::ref and std::cref Overview
std::ref: Creates a std::reference_wrapper around an object, which
allows it to be passed by reference rather than by value.

std::cref: Similar to std::ref, but it creates a
std::reference_wrapper<const T>, allowing you to pass the object
as a constant reference, meaning the object cannot be modified
through the reference.

Why Use std::ref and std::cref?
When passing objects to functions that accept arguments by value
(e.g., when using std::bind or std::thread), std::ref and std::cref
ensure that the objects are passed by reference instead.

They allow you to store references in standard containers like
std::vector that normally require copies.

*/

void increment( int& n ) {
   ++n;
}

int main( ) {
   int value = 5;

   // Using std::ref to pass value by reference
   std::function<void( )> func = std::bind( increment, std::ref( value ) );

   func( );  // Increment `value` through the bound function
   std::cout << "Value after increment: " << value << std::endl; // Output: Value after increment: 6

   return 0;
}
