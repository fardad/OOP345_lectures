#include <iostream>
using namespace std;
int main() {
   int* p = (int*)400;
   int a[50] = { 20, 30, 40, 50, 60 };
   cout << unsigned(p) << endl;
   int q = 400;
   cout << q << endl;
   p++;
   q++;
   cout << unsigned(p) << endl;
   cout << q << endl;
   p = a;
   cout << *a << " " << p[0] << endl;
   do {
      cout << *p << endl;
      p++;
   } while (p != &a[5]);
   return 0;
}