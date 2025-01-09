// lecture video at: https://youtu.be/N_baE60Yu-o

#include <iostream>
using namespace std;
int main( ) {
   int a[3][4]{
      {10, 20, 30, 40 },
      {50, 60, 70 , 80 },
      {90, 100, 110, 120 }
   };
   int* p = reinterpret_cast<int*>(a);
   for ( int i = 0; i < 12; cout << p[i++] << " " );
   cout << endl;

   for ( int j = 0; j < 3; j++ ) {
      for ( int k = 0; k < 4; cout << a[j][k++] << " " );
      cout << endl;
   }

   return 0;
}