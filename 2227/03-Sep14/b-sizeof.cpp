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
int main() {
   int a = 17;
   int b = 017;
   int c = 0x17;
   cout << "size of Coord " << sizeof(Coord) << endl;
   cout << "size of Coord " << sizeof(CoordId) << endl;
   cout << "size of Coord " << sizeof(test) << endl;
   cout << "size of Coord " << sizeof(test2) << endl;
   cout << "size of Coord " << sizeof(test3) << endl;
   return 0;
}