#include <iostream>
using namespace std;
int val( ) {
   size_t s = 0;
   return s++;
}
int sval( ) {
   static size_t s = 0;
   return s++;
}
int main() {
   int i{ };
   for ( i = 0; i < 10; i++ ) {
      cout << val( ) << endl;
   }
   for ( i = 0; i < 10; i++ ) {
      cout << sval( ) << endl;
   }
   return 0;
}