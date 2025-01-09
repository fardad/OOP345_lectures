
#include <iostream>
#include <functional> 
using namespace std;

// A function to add three numbers
int addThree( int a, int b, int c ) {
   return a + b + c;
}

int main( ) {
   // Bind the first two arguments and leave the third open
   auto addFiveAndTen = bind( addThree, 5, 10, placeholders::_1 );

   // Call the new function with the third argument
   cout << "Result: " << addFiveAndTen( 7 ) << endl; // Output: Result: 22

   return 0;
}
