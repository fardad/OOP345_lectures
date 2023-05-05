#include <iostream>
using namespace std;

int main() {
  
   int a[3] = { 10, 20, 30 };
   int b[2][3] = { { 100, 200, 300 },{400,500,600} };
   int c[300][3] = { { 100, 200, 300 },{400,500,600} };
   cout << (unsigned)a << endl;
   cout << (unsigned)(a + 1) << endl;
   cout << (unsigned)b[0] << endl;
   cout << (unsigned)(b[0] + 1) << endl;
   cout << (unsigned)b << endl;
   cout << (unsigned)(b + 1) << endl;
   cout << "-------------------------------------" << endl;
   cout << a[1] << endl;
   cout << *(a + 1) << endl;
   cout << b[1][2] << endl;
   cout << *(b[1] + 2) << endl;
   cout << *(*(b + 1) + 2) << endl;
   int* p = a;
   cout << p[2] << endl;
   int** q = (int**)400;
   cout << unsigned(q + 1) << endl;
   int(*r)[3] = b; // pointer to a 2D array of ints with width of 3;

   r = c;

   return 0;
}