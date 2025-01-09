#include <iostream>
using namespace std;
#define sum(x, y) (x+y)
int main( ) {
   int a = 10;
   int b = 20;
   int c{};
   double e = 10.1, f = 20.2, g;
   c = sum(a, b) * 2;
   g = sum( e, f ) * 2;
   cout << c << endl;
   return 0;
}