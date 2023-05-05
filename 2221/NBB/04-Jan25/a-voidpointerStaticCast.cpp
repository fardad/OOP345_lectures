#include <iostream>
using namespace std;
void copyMem(void* des, const void* src, size_t size) {
   char* cdes = static_cast<char*>(des);
   const char* csrc = static_cast<const char*>(src);
   unsigned int i;
   for (i = 0; i < size; i++) {
      cdes[i] = csrc[i];
   }
}

void copyMem(char* des, const char* src, size_t size) {
   unsigned int i;
   for (i = 0; i < size; i++) {
      des[i] = src[i];
   }
}
int main() {
   int a = 24;
   int b;
   double c = 234.567;
   double d;
   copyMem((char*)&b, (const char*)&a, sizeof(a));
   copyMem((char*)&d, (const char*)&c, sizeof(c));
   cout << b << endl;
   cout << d << endl;
   copyMem(&b, &a, sizeof(a));  // no need to cast since receiving argument is void *
   copyMem(&d, &c, sizeof(c));
   cout << b << endl;
   cout << d << endl;

   return 0;
}