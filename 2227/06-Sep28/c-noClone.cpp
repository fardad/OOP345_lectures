#include <iostream>
#include "DynArray.h"
using namespace std;
using namespace sdds;
template<typename type, int Tsize>
void display(const DynArray<type, Tsize>& A) {
   for (int i = 0; i < A.size()+3; i++) {
      cout << (i + 1) << ": " << A[i] << endl;
   }
}
int main() {
   DynArray<double, 10> A;
   for (int i = 0; i < 5; i++) {
      A[i] = i * 123.456789;
   }
   cout << A << endl;
   display(A);
   return 0;
}
