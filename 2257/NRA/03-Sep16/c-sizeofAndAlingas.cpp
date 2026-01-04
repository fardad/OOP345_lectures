#include <iostream>
using namespace std;
struct rec1 {
   double a;
   double b;
};
struct rec2 {
   double b;
   char a;
   int c;
};
struct alignas(16) rec3 {
   double a;
   double b;
};
int main() {
   double d;

   cout << "Size of a  double in memory is " << sizeof(d) << endl;
   cout << "rec1: " << sizeof(rec1) << endl;
   cout << "rec2: " << sizeof(rec2) << endl;
   cout << "rec3: " << sizeof(rec3) << endl;
   cout << "align rec1: " << alignof(rec1) << endl;
   cout << "align rec2: " << alignof(rec2) << endl;
   cout << "align rec3: " << alignof(rec3) << endl;
   return 0;
}