#include <iostream>
using namespace std;
int main() {
   int a[5]{ 1,2,3,4,5 };
   int* p = a;
   const int* const aa = a;
   cout << (unsigned)p << " " << (unsigned)a << endl;
   a[1] = 20;
   for (int i = 0; i < 5; i++) {
      cout << p[i] << endl;
   }
   p++;
   cout << p[0] << endl;
   cout << a[1] << endl;
   return 0;
}