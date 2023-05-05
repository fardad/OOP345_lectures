#include <iostream>
using namespace std;
//void prnN34(int* a[][3][4], int rows);    //   foo(int a[]) ==> foo(int* a);
void prnN34(int(*a)[3][4], int rows) {   //   foo(int a[]) ==> foo(int* a);
      int i, j, k;
   for (int i = 0; i < rows; i++) {
      for (j = 0; j < 3; j++) {
         for (k = 0; k < 4; k++) {
            cout << a[i][j][k] << " ";
         }
         cout << endl;
      }
      cout << endl;
   }
   cout << endl;
}


int main() {
   int a[2][3][4]{
      {{1,2,3,4 },{5,6, 7,8 }, {9,10,11,12 }},
      {{10,20,30,40 },{50,60, 70,80 }, {90,100,110,120 }}
   };
   int b[3][3][4]{
      {{1,2,3,4 },{5,6, 7,8 }, {9,10,11,12 }},
      {{10,20,30,40 },{50,60, 70,80 }, {90,100,110,120 }},
      {{100,200,300,400 },{500,600, 700,800 }, {900,1000,1100,1200 }}
   };
   prnN34(a, 2);
   prnN34(b, 3);
}
