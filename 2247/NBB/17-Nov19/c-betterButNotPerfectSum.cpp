#include <iostream>
using namespace std;
#define sum(x, y) (x+y)
int main( ) {
   int a = 10;
   int b = 20;
   int c{};
   c = sum(a, b) * 2;
   cout << c << endl;
   return 0;
}