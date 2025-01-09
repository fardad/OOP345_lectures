#include <iostream>
using namespace std;
// these are all C language
#define sum(x, y) ((x) + (y))
#define prod(x, y) ((x) * (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))  // <--- how can this go wrong?
// multiple line macro
#define fromTo(x , y) \
   do { \
     cout << x << " "; \
   } while (x++ < y); \
   cout << endl 

int main( ) {
   int a = 2;
   int b = 5;
   int c{};
   c = sum( a, b ) * 2; // 10
   cout << c << endl;
   c = prod( a, b ) + 2; // 8
   cout << c << endl;
   c = sum( a + 1, b + 1 ) * 2; // ?
   cout << c << ',';
   c = prod( a + 1, b + 1 ) + 2; // ?
   cout << c << endl;
   cout << min( a, b ) << endl;
   fromTo( a, b );
   return 0;
}
