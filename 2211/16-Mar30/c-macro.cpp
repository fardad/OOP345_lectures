#include <iostream>
using namespace std;

int max(int a, int b) {
   return a > b ? a : b;
}

int main() {
   int a, b = 10, c = 20;
   for (int i = 0; i < 50000000; i++) {
      a = max(b, c);
   }
   return 0;
}
