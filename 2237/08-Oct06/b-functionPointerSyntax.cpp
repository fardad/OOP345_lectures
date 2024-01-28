#include <iostream>
using namespace std;
void sum( int a, int b ) {
   cout << (a + b) << endl;
}
void prod( int a, int b ) {
   cout << (a * b) << endl;
}
auto main( ) -> int {
   cout << "08-Oct06 OOP345 NBB" << endl;
   int x = 10;
   int y = 5;
   void   (*funcptr)(int, int) = nullptr;

   funcptr = sum;
   cout << unsigned( sum ) << endl;
   cout << unsigned( funcptr ) << endl;
   //(*funcptr)(10, 20); // C language call for pointer to a function
   funcptr( 10, 30 ); // call the sum fucntion

   funcptr = prod;
   cout << unsigned( prod ) << endl;
   cout << unsigned( funcptr ) << endl;

   funcptr( 10, 30 ); // call the prod fucntion

   return 0;
}