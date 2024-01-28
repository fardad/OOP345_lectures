#include <iostream>
using namespace std;



int main() {
   double d[2][3][4];
   double(*pd)[3][4];
   int a[3] = { 10, 20, 30 };
   int b[2][4] = { { 100, 200, 300, 400 },{500,600,700, 800} };
   int c[200][4] = { { 100, 200, 300, 400 },{500,600,700, 800} };
   cout << reinterpret_cast<size_t>(a) << endl;
   cout << reinterpret_cast<size_t>(a+1) << endl;
   cout << a[1] << endl;
   cout << *(a + 1) << endl;
   cout << b[1][2] << endl;
   cout << *b[0] << " " << *b[1] << endl; 
   cout << b[1][2] << endl;
   cout << *(b[1] + 2) << endl;
   cout << *(*(b + 1) + 2) << endl;
   cout << reinterpret_cast<size_t>(b) << endl;
   cout << reinterpret_cast<size_t>(b+1) << endl;
   int* p = a;
   cout << p[2] << endl;
   auto q = b;
   cout << q[1][1] << endl;
   int (*r)[4]; // creates an array to a 2 dimensional array with width of 4;
   r = b;
   cout << r[1][2] << endl;

   return 0;
}