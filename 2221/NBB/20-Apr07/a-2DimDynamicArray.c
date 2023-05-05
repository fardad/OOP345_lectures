#include <iostream>
using namespace std;
int main() {
   int** p = new int* [10];
   int i = 0;
   int j;
   int size = 10;
   for (i = 0; i < 10; i++) {
      p[i] = new int[size++];
   }
   for (size = 10, i = 0; i < 10; i++, size++) {
      for (j = 0; j < size; j++) {
         p[i][j] = (j + 1) * 10;
      }
   }
   for (size = 10, i = 0; i < 10; i++, size++) {
      for (j = 0; j < size; j++) {
         cout << p[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
   for (i = 0; i < 10; i++) {
      delete[] p[i];
   }
   delete[] p;

   return 0;
}