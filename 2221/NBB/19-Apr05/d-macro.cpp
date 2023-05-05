#include <iostream>
using namespace std;
// macro
#define SUM(x, y)  ((x) + (y))
#define max(x, y) ((x)>(y)?(x):(y)) 

int main() {
   int a = 10, b = 20, c;
   double d = 10.1, e = 20.2, f;
   c = SUM(a,b) * 2;
   cout << c << " - ";
   f = SUM(d, e) * 2;
   cout << f << endl;
   cout << max(b, a) << endl;
   return 0;
}