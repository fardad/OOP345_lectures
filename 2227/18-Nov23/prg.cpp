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
int main() {
   int b[2][3][4][5];
   int (*p)[3][4][5] = b;
   return 0;
}