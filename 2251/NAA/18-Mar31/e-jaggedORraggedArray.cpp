#include <iostream>
#include <iomanip>
using namespace std;




int main() {
   int* jagged[4]{};

   jagged[0] = new int[8] {21, 22, 23, 24, 25, 26, 27, -1};
   jagged[1] = new int[4] {1, 2, 3, -1};
   jagged[2] = new int[10] {31, 32, 33,34,35,36,37,38,39, -1};
   jagged[3] = new int[6] {11, 12, 13, 14, 15, -1};

   for (int i = 0; i < 4; i++) {
      for (int j = 0; jagged[i][j] >= 0; j++) {
         cout << setw(4) << jagged[i][j];
      }
      cout << endl;
   }
   cout << endl;

   return 0;
}