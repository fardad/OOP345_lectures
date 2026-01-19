#include <iostream>
using namespace std;
int main( ) {
   int ar[5]{ 10, 20, 30, 40, 50 };
   cout << *(ar + 3) << endl;
   int* p = ar;
   p += 2;
   cout << p[0] << endl;
   cout << *(p - 1) << endl;
   cout << p[-2] << endl;
   return 0;
}