#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void memCpy(void* des, void* src, size_t size) {
   for (size_t i = 0; i < size; i++) {
      ((char*)des)[i] = ((char*)src)[i];
   }
}

int main() {
   int ar[] = { 1, 2,3 ,4 };
   int* p = ar;
   double a = 1234.5678987, b;
   int i = 123, j;

   cout << unsigned(p) << endl;
   cout << p[0] << endl;
   p++;
   cout << unsigned(p) << endl;
   cout << p[0] << endl;
   memCpy(&j, &i, sizeof(i));
   cout << j << endl;
   memCpy(&b, &a, sizeof(a));
   cout << a << endl;
   return 0;
}

