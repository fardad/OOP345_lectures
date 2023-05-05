#include <iostream>
using namespace std;
void prn2Dint(int a[][5], int rows) {
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < 5; j++) {
         cout << a[i][j] << "\t";
      }
      cout << endl;
   }

}

void prn2DintPtrVersion(int (*a)[5], int rows) {
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < 5; j++) {
         cout << a[i][j] << "\t";
      }
      cout << endl;
   }

}

int main() {
   int i, j;
   char b[2][3][4];
   // sizeof target of b is 12
   // sizeof target of b[0]  is 4
   // sizeof target of b[0][0]  is 1
   int a[3][5] = {
      {1,2,3,4,5},
      {6,7,8,9,10},
      {11,12,13,14,15}
   };
   int* p = (int*)a;
   int (*q)[5]; // one integer pointer of and array with with of 5
   int* r[5];   // an array of 5 integer pointers;
   q = a;
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 5; j++) {
         cout << a[i][j] << "\t";
      }
      cout << endl;
   }
   for (i = 0; i < 15; i++) {
      cout << p[i] << " ";
   }
   cout << endl;
   cout << (unsigned)p << " " << (unsigned)a << endl;
   cout << (unsigned)(p + 1) << endl;
   cout << (unsigned)(a[0] + 1) << endl;
   cout << (unsigned)(a + 1) << endl;
   return 0;
}