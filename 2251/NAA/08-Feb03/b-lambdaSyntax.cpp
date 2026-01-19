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
int main(){
auto add = []( int a, int b ) -> int {
   return a + b;
   };

std::cout << add( 3, 4 ) << std::endl;  // Outputs 7

cout << []( double a, double b ) -> double { return a * b; }(10, 20) << endl;

return 0;
}

