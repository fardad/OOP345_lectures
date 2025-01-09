#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct Coord {
   double x, y;
};
struct CoordId {
   double x, y;
   long long val;
   char id;
};
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
void foo( char* str ) {
   cout << "size in foo: " << sizeof( str ) << endl;
}
int main( ) {
   char s[1000];
   foo( s );
   cout << "in main: " << sizeof( s ) << endl;
   cout << "size of Coord " << sizeof( Coord ) << endl;
   cout << "size of Coord " << sizeof( CoordId ) << endl;
   cout << "size of test " << sizeof( test ) << endl;
   cout << "size of test2 " << sizeof( test2 ) << endl;
   cout << "size of test3 " << sizeof( test3 ) << endl;
   return 0;
}