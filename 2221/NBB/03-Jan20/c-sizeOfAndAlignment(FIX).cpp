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
   long b;
   char c;
   long i;
   double d;
};
struct test2 {
   double d;
   long b;
   long i;
   char c;
};
int main() {
   int a = 197520;
   double* p = (double*)197520;
   int* q = (int*)197520;
   short* r = (short*)197520;
   Coord* c = (Coord*)197520;
   a++;
   cout <<"a: " <<  a << endl;
   p++;
   q++;
   r++;
   c++;
   cout << "p: " << unsigned(p) << endl;
   cout << "q: " << unsigned(q) << endl;
   cout << "r: " << unsigned(r) << endl;
   cout << "c: " << unsigned(c) << endl;
   cout << alignof(Coord) << endl;
   cout << "size of Coord:" << sizeof(Coord) << endl;
   cout << "alignmet of coord: " << alignof(Coord) << endl;
   cout << "size of CoordId:" << sizeof(CoordId) << endl;
   cout << "alignmet of coordId: " << alignof(CoordId) << endl;
   cout << sizeof(test) << endl;
   cout << sizeof(test2) << endl;
   return 0;
}