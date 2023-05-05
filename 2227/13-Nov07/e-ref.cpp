#include <iostream>
#include <functional>
#include <vector>
using namespace std;

void inc(int& x, int& y) {
   ++x;
   ++y;
}

int main() {
   int a = 10, b = 10;
   
   auto addone = bind(inc, ref(a), b);

   addone();

   cout << "a: " << a << ", b: " << b << endl;

   return 0;
}
