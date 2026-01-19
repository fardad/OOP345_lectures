#include <iostream>
using namespace std;
void foo(int ptr[], size_t size) {
   for (size_t i = 0; i < size; i++) {
      cout << ptr[i] << " ";
   }
   cout << endl;
}



int main() {
   cout << "18-Mar31 OOP345 NAA" << endl;

   


   int arr[4][3] = {
      { 10, 20, 30 },
      { 110, 120, 130 },
      { 210, 220, 230 },
      { 310, 320, 330 }
   };
   int arr2[8][3] = {
      { 10, 20, 30 },
      { 110, 120, 130 },
      { 210, 220, 230 },
      { 310, 320, 330 },
      { 10, 20, 30 },
      { 110, 120, 130 },
      { 210, 220, 230 },
      { 310, 320, 330 }
   };
   int (*ptr)[3] = arr;
   
   int ar3d[10][2][4];

   int (*p)[2][4] = ar3d;

   for (size_t i = 0; i < 4; i++){
      foo(ptr[i], 3);
   }
   ptr = arr2;
   cout << "--------------------" << endl;
   for (size_t i = 0; i < 8; i++) {
      foo(ptr[i], 3);
   }

   return 0;
}