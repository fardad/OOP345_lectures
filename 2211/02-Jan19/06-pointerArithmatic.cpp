#include <iostream>
using namespace std;
int main() {
   int* p = (int*)8;
   cout << int(p) << endl;
   p++;
   cout << int(p) << endl;
   double* q = (double*)8;
   cout << int(q) << endl;
   q++;
   cout << int(q) << endl;
   void* v = (void*)8;
   cout << int(v) << endl;
   v = ((int*)v)+1;
   cout << int(v) << endl;
   return 0;
}
