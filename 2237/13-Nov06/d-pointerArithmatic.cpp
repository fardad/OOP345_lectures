#include <iostream>
struct Doubles{
   double v[5];
};
using namespace std;
int main() {
   Doubles d[3];
   Doubles* dp = d;
   int a[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
   int* p = a;
   cout << *p << endl;
   p = &a[3];
   cout << *p << endl;
   cout << p[2] << endl;
   p = a;
   cout << reinterpret_cast<unsigned>(p) << endl;
   p = &a[1];
   cout << reinterpret_cast<unsigned>(p) << endl;
   p++; // next possible place for the target of p (int)
   cout << reinterpret_cast<unsigned>(p) << endl;
   cout << reinterpret_cast<unsigned>(dp) << endl;
   dp++;
   cout << reinterpret_cast<unsigned>(dp) << endl;
   return 0;
}