// lecture video at: https://youtu.be/N_baE60Yu-o

#include <iostream>
using namespace std;
int main( ) {
   int a[12] = { 10, 20, 30, 40, 50,60, 70, 80,90, 100, 110, 120 };
   int b[24] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };
   int a3[2][3][4]{};
   /*
   a3[1] ====> 1 means 3 x 4 that is 12
   a3[?][1] ====> 1 means 4
   a3[?][?][1] ====> 1 is 1   
   */

   int i, j, k;

   int ( *p )[4] = reinterpret_cast<int( * )[4]>(a);
   int ( *p3 )[3][4] = reinterpret_cast<int( * )[3][4]>(b);
   for ( j = 0; j < 3; j++ ) {
      for ( k = 0; k < 4; k++ ) {
         cout << p[j][k] << " ";
      }
      cout << endl;
   }

   for ( i = 0; i < 2; i++ ) {
      for ( j = 0; j < 3; j++ ) {
         for ( k = 0; k < 4; k++ ) {
            cout << p3[i][j][k] << " ";
         }
         cout << endl;
      }
   }

   cout << "size of a3 " << sizeof( a3 ) << endl;
   cout << "size of p3 " << sizeof( p3 ) << endl;

   return 0;
}