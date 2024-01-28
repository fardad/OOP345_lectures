#include <iostream>
using namespace std;

void copyMem(void* des, const void* src, size_t size) {
   char* cdes = static_cast<char*>(des);
   const char* csrc = static_cast<const char*>(src);
      for(size_t i = 0; i < size; i++) {
      cdes[i] = csrc[i];
   }
}

int main() {
   double a = 1234.56789;
   double b;
   copyMem(&b, &a, sizeof(double));
   cout << b << endl;
   return 0;
}