
#include <iostream>
#include <functional> 

using namespace std;
/*

std::bind is a function from the <functional> library in C++ that allows you
to create a function object by binding some or all of the arguments to a
function or callable object. This is useful when you need to partially
apply arguments to a function and create a new function with fewer parameters.

How Does std::bind Work?
std::bind takes a callable (like a function or a member function) and a
set of arguments and returns a new callable object with those arguments
bound. You can also use placeholders (std::placeholders::_1, _2, etc.)
to indicate where arguments should be provided when the new callable
is invoked.

*/

// A simple function to demonstrate bind
void greet( const string& name, const string& greeting, size_t num ) {
   for ( size_t i = 0; i < num; i++ )
      cout << greeting << ", " << name << "!" << endl;
}

int main( ) {
   // Create a function object that binds the first parameter ("John") and leaves the second open
   auto greetJohn = bind( greet, "John", placeholders::_1, placeholders::_2 );

   // Call the bound function with different greetings
   greetJohn( "Hello", 3 );  // Output: Hello, John!
   greetJohn( "Good evening", 4 );  // Output: Good evening, John!

   return 0;
}

