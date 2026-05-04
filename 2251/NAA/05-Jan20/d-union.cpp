#include <iostream>
using namespace std;
struct address {
   char country[15];
   union {
      size_t zip;
      char postal[6];
   } code;
};

union Vars {
   double a;
   int b;
   char c[7];
};

int main( ) {
   Vars V;
   cout << sizeof( Vars ) << endl;
   cout << alignof(Vars) << endl;
   cout << reinterpret_cast<unsigned long long>(&V.a) << endl;
   cout << reinterpret_cast<unsigned long long>(&V.c) << endl;
   V.a = 123456.789;
   cout << V.a << endl;
   V.b = 123456;
   cout << V.b << endl;
   for ( int i = 0; i < 7; i++ ) {
      V.c[i] = 'A' + i;
   }
   for ( int i = 0; i < 7; i++ ) {
      cout << V.c[i];
   }
   cout << endl;
   cout << V.a << endl;
   cout << V.b << endl;


   return 0;
}