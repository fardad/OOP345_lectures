#include <iostream>
using namespace std;
struct Rec {
   double a;
   double b;
};
int main(int argc, char* argv[], char* env[]) {
   char name[80] = "Fred";
   long  lg;
   char* c;
   int* i;
   double* d;
   Rec* r;
   cout << sizeof(long) << endl;
   cout << sizeof(lg) << endl;
   cout << sizeof(c) << endl;
   cout << sizeof(i) << endl;
   cout << sizeof(d) << endl;
   cout << sizeof(r) << endl;
   return 0;
}