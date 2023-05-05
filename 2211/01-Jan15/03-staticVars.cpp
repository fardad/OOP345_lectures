#include <iostream>
using namespace std;
void addOne() {
   static int val = 0;
   val++;
   cout << val << endl;
}

int main() {
   for (int i = 0; i < 10; i++) {
      addOne();
   }
   return 0;
}