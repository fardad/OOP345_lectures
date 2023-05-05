#include <iostream>
using namespace std;

//void copyMem(void* vdes, const void* vsrc, size_t size) {
//   char* des = (char*)vdes;
//   const char* src = (const char*)vsrc;
//   for (size_t i = 0; i < size; i++) {
//      des[i] = src[i];
//   }
//}
void copyMem(void* des, const void* src, size_t size) {
   for (size_t i = 0; i < size; i++) {
      ((char*)des)[i] = ((const char*)src)[i];
   }
}
int main() {
   double a = 1234.56789;
   double b;
   float f = 123.456;
   long l;
   short s;
   copyMem(&b,&a, sizeof(double));
   cout << b << endl;
   copyMem(&l, &f, sizeof(float));
   cout << l << endl;
   copyMem(&s, &a, sizeof(double));//<< will cause the program to crash
   cout << s << endl;
   return 0;
}