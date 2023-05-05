#include <iostream>
using namespace std;
union CID{
   double a;
   int b;
   char c[7];
};
struct scid {
   double a;
   int b;
   char c[8];
};


int main() {
   cout << sizeof(CID) << endl;
   cout << sizeof(scid) << endl;
   CID i;
   i.a = 1234.567;
   cout << i.a << endl;
   i.b = 987;
   cout << i.b << endl;
   for (int n = 0; n < 6; n++) {
      i.c[n] = 'x';
   }
   i.c[6] = 0;
   cout << i.c << endl;
   cout << i.a << endl;
   
   return 0;
}