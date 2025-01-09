
/*

Why Use std::function?
- Type Erasure: std::function can store any callable object with the
same signature, regardless of its type (e.g., functions, lambdas,
function objects).

- Flexibility: It allows for dynamic behavior in scenarios like
callback functions or passing functions as parameters to other
functions.

- Ease of Use: Provides a clean and simple way to handle function pointers or callable objects.


The term "type-erased" refers to a programming concept where the type
information of an object is hidden or "erased" in such a way that the
object's type is not known at compile time but still can be managed
and called at runtime. This allows you to handle objects of different
types in a uniform way, as long as they conform to a specific interface
or behavior.

In the context of std::function, type erasure means that std::function
can store and invoke any callable object (function, lambda, functor, etc.)
that matches its signature without needing to know the specific type of
the callable at compile time. The actual type information of the stored
callable is abstracted away, enabling std::function to provide a common
interface to call it.

How Type Erasure Works in std::function
When you create an std::function object, it can store any callable type
as long as it matches the specified signature. Internally, std::function
uses type erasure to store and manage the callable object without needing
to know its exact type. This is accomplished through mechanisms such
as polymorphism and dynamic memory allocation.


*/

#include <iostream>
#include <functional> // Include the <functional> header
using namespace std;
void myFunction( ) {
   std::cout << "Hello from myFunction!" << std::endl;
}

auto myLambda = []( ) {
   std::cout << "Hello from myLambda!" << std::endl;
   };


struct MyFunctor {
   void operator()( ) const {
      std::cout << "Hello from MyFunctor!" << std::endl;
   }
};


int main( ) {
   // Create std::function instances using type erasure
   std::function<void( )> func1 = myFunction;
   std::function<void( )> func2 = myLambda;
   std::function<void( )> func3 = MyFunctor( );

   // Invoke the stored callables
   func1( ); // Output: Hello from myFunction!
   func2( ); // Output: Hello from myLambda!
   func3( ); // Output: Hello from MyFunctor!

   return 0;
}