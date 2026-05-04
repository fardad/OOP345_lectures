
#include <iostream>
using namespace std;
struct dbls {
   double a;
   double b;
};
int main() {
   double vals[] = { 10.1, 20.2, 30.3, 40.4, 50.5 };
   dbls* p = reinterpret_cast<dbls*>(16);

   cout << reinterpret_cast<unsigned long long>(p) << endl;
   p++;
   cout << reinterpret_cast<unsigned long long>(p) << endl;
   p++;
   cout << reinterpret_cast<unsigned long long>(p) << endl;
   p++;
   cout << reinterpret_cast<unsigned long long>(p) << endl;
   p++;
   cout << reinterpret_cast<unsigned long long>(p) << endl;
   return 0;
}