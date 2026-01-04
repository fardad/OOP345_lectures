#include <iostream>
#include "Array.h"
using namespace seneca;
using namespace std;
struct Rec{
   int a{};
   double b{};
};
ostream& operator<<(ostream& ostr, const Rec& R) {
   return cout << R.a << " - " << R.b;
}

int main() {
   cout << "05-Sep23 OOP345 NRA" << endl;
   Rec r{ 20, 30.3 }, s{ 10, 20.333 };
   Array<int> I(4);
   Array<double> D(5);
   Array<Rec> R(10);
   cout << r << endl;
   cout << I << endl << D << endl;
   for (size_t i = 0; i < 7; i++) {
      R[i] = Rec{ static_cast<int>(i) + 10, static_cast<int>(i) + 10.234 };
   }
   for (size_t i = 0; i < 20; i++) {
      I[i] = static_cast<int>(i) + 10;
   }
   for (size_t i = 0; i < 10; i++) {
      D[i] = static_cast<int>(i) + 10.123;
   }
   cout << I << endl << D << endl << R << endl;
   return 0;
}

