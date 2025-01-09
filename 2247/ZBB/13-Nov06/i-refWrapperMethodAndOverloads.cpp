#include <iostream>
#include <functional> 
#include <vector>
using namespace std;
/*

Key Method of std::reference_wrapper
get(): Returns the underlying reference.

Implicit conversion: std::reference_wrapper can often be used directly in places
where a reference is expected, thanks to implicit conversion to Type&.


Benefits of std::reference_wrapper
Preserve References: Allows you to store references in containers that
do not natively support them.

Safe Reference Management: Ensures that the reference is correctly managed
and not inadvertently turned into a pointer or copy.

Standard Library Integration: Works seamlessly with algorithms and functions
that expect values.


When Not to Use std::reference_wrapper

When you only need to work with pointers or already have ways to manage
references without a container, std::reference_wrapper may be unnecessary.

Be cautious when the lifetime of the referenced object is shorter than
that of the std::reference_wrapper, as it will lead to undefined behavior.

In summary, std::reference_wrapper is a helpful tool for handling references
in scenarios where normal references or pointers are inconvenient, especially in containers.

*/

#include <iostream>
#include <functional>

void printValue( int& val ) {
   cout << "Value: " << val << endl;
}

int main( ) {
   int num = 42;

   // Create a reference wrapper and pass it to a function
   reference_wrapper<int> refNum = num;
   printValue( refNum ); // Output: Value: 42

   cout << refNum << endl; // Output: Value: 42

   cout << refNum.get( ) << endl; // Output: Value: 42

   return 0;
}

