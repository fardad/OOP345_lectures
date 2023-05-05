#include <iostream>
using namespace std;
void prnPackOfThreeInts(int array[][3], int length) {
   for (int i = 0; i < length; i++) {
      for (int j = 0; j < 3; j++) {
         if (j) cout << ", ";
         cout << array[i][j];
      }
      cout << endl;
   }
}
void prnInts(int* array, int length) {
   for (int i = 0; i < length; i++) {
      if (i) cout << ", ";
      cout << array[i];
   }
   cout << endl;
}
int main() {
   int a[3] = { 10, 20, 30 };
   int b[2][3] = { { 100, 200, 300 },{400,500,600} };
   int* p = a;
   prnInts(p,3);
   p = (int*)b;
   prnInts(p, 6);
   return 0;
}