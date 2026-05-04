#include <iostream>
using namespace std;
struct T1 {
   char c;
   double d;
   int i;
};
struct T2 {
   double d;
   int i;
   char c;
};
int main( ) {
   cout << sizeof( T1 ) << endl;
   cout << alignof( T1 ) << endl;
   cout << sizeof( T2 ) << endl;
   cout << alignof( T2 ) << endl;

   return 0;
}