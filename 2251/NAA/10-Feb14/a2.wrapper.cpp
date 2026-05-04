/*
 A wrapper class template in C++ is a class template that acts
 as a container or "wrapper" around an existing data type. It
 is used to add additional functionality to the type it wraps
 without modifying the original type. Wrapper class templates
 are especially useful when you want to create generic code
 that can handle different types while still providing some
 specific behaviors.


- Generic: The wrapper class template can work with any data
type.
- Reusable: The same wrapper can be used to create objects
for int, double, std::string, etc.
 - Extensible: You can add more member functions or functionality
to the wrapper without modifying the type it wraps.

*/


#include <iostream>
#include <string>
using namespace std;


// A simple wrapper class template
template <typename T>
class Wrapper {
private:
   T value; // The wrapped value
public:
   // Constructor
   Wrapper( T val ) : value( val ) { }

   // Function to get the value
   T getValue( ) const {
      return value;
   }

   void setValue( T val ) {
      value = val;
   }

   // Function to display the value
   void display( ) const {
      cout << "Value: " << value << endl;
   }
};

int main( ) {
   // Wrapping an int
   Wrapper<int> intWrapper( 42 );
   intWrapper.display( ); // Output: Value: 42
   intWrapper.setValue( 25 );
   intWrapper.display( ); // Output: Value: 25

   // Wrapping a double
   Wrapper<double> doubleWrapper( 3.14 );
   doubleWrapper.display( ); // Output: Value: 3.14

   // Wrapping a string
   Wrapper<string> stringWrapper( "Hello, World!" );
   stringWrapper.display( ); // Output: Value: Hello, World!

   return 0;
}