// float_vs_double.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   float f1 = 1234567.0f;      // 7 digits
   float f2 = 12345678.0f;     // 8 digits
   float f3 = 0.0001234567f;   // 7 digits
   float f4 = 0.00012345678f;  // 8 digits

   double d1 = 123456789012345.0;  // 15 digits
   double d2 = 1234567890123456.0; // 16 digits (may lose accuracy)

   cout << setprecision(17); // show more digits

   cout << "float examples:" << endl;
   cout << "f1 = " << f1 << endl;
   cout << "f2 = " << f2 << endl;
   cout << "f3 = " << f3 << endl;
   cout << "f4 = " << f4 << endl;

   cout << "\ndouble examples:" << endl;
   cout << "d1 = " << d1 << endl;
   cout << "d2 = " << d2 << endl;
   return 0;
}