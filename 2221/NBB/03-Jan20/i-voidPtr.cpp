#include <iostream>
using namespace std;
struct Student {
   char name[51];
   int stno;
};
void copyMem(void* des, const void* src,size_t size) {
   char* chdes = (char*)des;
   const char* chsrc = (const char*)src;
   for (unsigned int i = 0; i < size; i++) {
      chdes[i] = chsrc[i];
   }
}
int main() {
   double a = 23.456;
   double b;
   copyMem(&b,&a, sizeof(double));
   cout << b << endl;
   cout << sizeof(char*) << endl
      << sizeof(int*) << endl
      << sizeof(short*) << endl 
      << sizeof(Student*) << endl;
      return 0;
}