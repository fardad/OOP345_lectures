#include <iostream>
using namespace std;
//array of cubes with diements of 3x4x5
int main() {
   int(*ac)[3][4][5] = new int[100][3][4][5];

   delete[] ac;
   return 0;
}