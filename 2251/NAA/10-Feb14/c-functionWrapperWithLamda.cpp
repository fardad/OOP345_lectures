#include <iostream>
#include <functional> // Include the <functional> header
using namespace std;

int main( ) {
   // Lambda that takes two integers and returns their sum
   auto lambdaSum = []( int x, int y ) {
      return x + y;
      };

   // Wrap the lambda with function
   function<int( int, int )> funcWrapper = lambdaSum;

   // Call the wrapped lambda
   cout << "Lambda sum result: " << funcWrapper( 4, 6 ) << endl; // Output: Lambda sum result: 10

   return 0;
}
