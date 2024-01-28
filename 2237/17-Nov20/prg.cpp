#include <iostream>
using namespace std;

void print(int b[][4], int NoOfArrays) {

}

union MulArray {
   double* dptr;
   int* iptr;
   char* cptr;
};

int main() {

   MulArray ma[3]{};

   int b[2][4] = { { 100, 200, 300, 400 },{500,600,700, 800} };
   int* a = reinterpret_cast<int*>(b);
   int** p = new int* [4];
   p[0] = new int[2];
   p[1] = new int[10];
   p[2] = new int[20];
   p[3] = new int[4];

   p[1][3] = 123;
   cout << p[1][3] << endl;

   for (size_t i = 0; i < 8; i++) {
      cout << a[i] << " ";
   }
   cout << endl;
   return 0;
}