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
int main( ) {
   int a = 197520;
   double* p = reinterpret_cast<double*>(197520);
   int* q = reinterpret_cast<int*>(197520);
   short* r = reinterpret_cast<short*>(197520);
   Coord* c = reinterpret_cast<Coord*>(197520);
   cout << "p: " << (unsigned)p << endl;
   cout << "q: " << reinterpret_cast<unsigned long long>(q) << endl;
   cout << "r: " << reinterpret_cast<unsigned long long>(r) << endl;
   cout << "c: " << reinterpret_cast<unsigned long long>(c) << endl;
   a++;
   cout << "a: " << a << endl;
   p++;
   q++;
   r++;
   c++;
   cout << "p: " << (unsigned)p << endl;
   cout << "q: " << reinterpret_cast<unsigned long long>(q) << endl;
   cout << "r: " << reinterpret_cast<unsigned long long>(r) << endl;
   cout << "c: " << reinterpret_cast<unsigned long long>(c) << endl;
   cout << alignof(Coord) << endl;
   cout << "size of Coord:" << sizeof( Coord ) << endl;
   cout << "alignmet of coord: " << alignof(Coord) << endl;
   cout << "double: " << sizeof( double ) << endl;
   cout << "double: " << sizeof( double ) << endl;
   cout << "double: " << sizeof( long long ) << endl;
   cout << "double: " << sizeof( char ) << endl;
   cout << "size of CoordId:" << sizeof( CoordId ) << endl;
   cout << "alignmet of coordId: " << alignof(CoordId) << endl;
   cout << sizeof( test ) << endl;
   cout << sizeof( test2 ) << endl;
   return 0;
}