#include <iostream>
using namespace std;
int main() {
   int a[] = { 1,3, 5 };
   //for (int i = 0; i < 3; i++) {
   //   cout << a[i] << endl;
   //}
   for (int& e : a) {
      e++;
      cout << e << endl;
   }
   return 0;
}