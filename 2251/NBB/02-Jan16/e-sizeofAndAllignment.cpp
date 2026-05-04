#include <iostream>
using namespace std;
struct test {
   char c;
   double d;
   int i;
};
struct test2 {
   double d;
   int i;
   char c;
};
struct test3 {
   char c;
   int i;
   double d;
};
int main( ) {
   cout << "char: " << sizeof( char ) << endl;
   cout << "int: " << sizeof( int ) << endl;
   cout << "double: " << sizeof( double ) << endl;
   cout << sizeof( test ) << endl;
   cout << sizeof( test2 ) << endl;
   cout << sizeof( test3 ) << endl;
   cout << alignof( test ) << endl;
   cout << alignof( test2 ) << endl;
   cout << alignof( test3 ) << endl;

   return 0;
}