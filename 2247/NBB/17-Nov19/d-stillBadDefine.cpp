#include <iostream>
using namespace std;
#define sum(x, y) (x + y)
#define prod(x, y) (x * y)
int main( ) {
   int a = 2;
   int b = 3;
   int c{};
   c = sum( a, b ) * 2; // 10
   cout << c << endl;
   c = prod( a, b ) + 2; // 8
   cout << c << endl;
   c = sum( a + 1, b + 1 ) * 2; // ?
   cout << c << ',';
   c = prod( a + 1, b + 1 ) + 2; // ?
   cout << c << endl;
   return 0;
}

// 999,999