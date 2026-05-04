#include <iostream>
#include <cstdlib>
using namespace std;
#define PI 3.14159265

#define sum(x, y)  ((x)+(y))
#define mul(x, y)  ((x) * (y))
int main() {
   int a = 10, b = 30;
   double r = 2.34;
   cout << __FILE__ << endl;
   cout << __DATE__ << endl;
   cout << __TIME__ << endl;

   cout << 3.14159265 * r * r << endl;
   
   cout << mul(2, 1 + 2) << endl;
   cout << (2) * (1 + 2) << endl;
   cout << sum(a, b) * 2 << endl;
   cout << ((a)+(b)) * 2 << endl;

   return 0;
}