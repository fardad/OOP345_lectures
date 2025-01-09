#include <iostream>
using namespace std;
int main( ) {
   int arr[3][4][6][9];
   int ( *arrptr )[4][6][9];
   int a[3][4]{ {1,2,3,4} ,{5,6,7,8 }, {9,10,11,12 } };
   int (*x)[4];
   x = a;
   int* p = reinterpret_cast<int*>(a);
   for ( int i = 0; i < 12; i++ ) {
      cout << p[i] << " ";
   }
   cout << endl;
   cout << *a[0] << endl;
   cout << *a[1] << endl;
   cout << *a[2] << endl;
   for ( int j = 0; j < 3; j++ ) {
      for ( int k = 0; k < 4; k++ ) {
         cout << x[j][k] << " ";
      }
      cout << endl;
   }
   (arr[1][1] + 1); // 1 is 4 x 6 x 9 x sizeof int
   (arr[1][1][1] + 1); // 1 is 6 x 9 x sizeof int
   return 0;
}