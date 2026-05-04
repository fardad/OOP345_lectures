#include <iostream>
using namespace std;
struct T1 {
   char c;
   double d;
   int i;
};
int main( ) {
   char* c{};
   double* d{};
   T1* t{};
   cout << sizeof( c ) << endl;
   cout << sizeof( d ) << endl;
   cout << sizeof( t ) << endl;
   cout << reinterpret_cast<unsigned long long>(c) << endl;
   cout << reinterpret_cast<unsigned long long>(d) << endl;
   cout << reinterpret_cast<unsigned long long>(t) << endl;
   c++;
   d++;
   t++;
   cout << reinterpret_cast<unsigned long long>(c) << endl;
   cout << reinterpret_cast<unsigned long long>(d) << endl;
   cout << reinterpret_cast<unsigned long long>(t) << endl;
   return 0;
}
