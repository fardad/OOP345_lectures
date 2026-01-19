#define _CRT_SECURE_NO_WARNINGS
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

   cout << "size of test " << sizeof( test ) << endl;
   cout << "size of test2 " << sizeof( test2 ) << endl;
   cout << "size of test3 " << sizeof( test3 ) << endl;
   return 0;
}