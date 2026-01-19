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
   cout << "Sizeof T1: " << sizeof( T1 ) << endl;
   cout << "Sizeof T2: " << sizeof( T2 ) << endl;
   cout << "Alignof T1: " << alignof(T1) << endl;
   cout << "Alignof T2: " << alignof(T2) << endl;
   return 0;
}