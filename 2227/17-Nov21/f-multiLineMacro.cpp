#include <iostream>
using namespace std;
#define max(x,y) ((x)>(y)\
?(x):(y))
int main() {
   int a = 10;
   int b = 20;
   double d = 2.2;
   double e = 3.3;
   cout << max(d, e) << endl;
   return 0;
}

