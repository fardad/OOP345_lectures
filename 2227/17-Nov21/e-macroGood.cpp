#include <iostream>
using namespace std;
#define sum(x,y) ((x)+(y)) // search for sum replace with a+b
#define max(x,y) ((x)>(y)?(x):(y))
#define mul(x,y) ((x)*(y))
int main() {
   int a = 10;
   int b = 20;
   double d = 2.2;
   double e = 3.3;
   cout << sum(a,b) * 2 << endl;
   cout << sum(d,e) * 2 << endl;
   cout << max(d, e) << endl;
   cout << mul(a, b + 20) << endl;
   return 0;
}

