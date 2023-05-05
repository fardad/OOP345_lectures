#include <iostream>
#include <string>
#include "Container.h"
#include "DynArray.h"
using namespace std;
using namespace sdds;
template <typename type>
void printDynArray(const DynArray<type>& d, string title) {
   cout << title << endl << d << endl;
}
template <typename type>
void setToValue(DynArray<type>& d, const type& value) {
   for (int i = 0; i < d.size(); i++) {
      d[i] = value;
   }
}
int main() {
   DynArray<double> d(10);
   printDynArray(d, "double garbage");
   setToValue(d, 12.23);
   printDynArray(d, "All 1.23");

   DynArray<int> I(10);
   printDynArray(I, "integer garbage");
   setToValue(I, 10);
   printDynArray(I, "All 10");

   DynArray<Container<int>> C(5);
   Container<int> ten("Ten", 10);
   printDynArray(C, "Container garbage");
   setToValue(C, ten);
   printDynArray(C, "All TEN");


   return 0;
}