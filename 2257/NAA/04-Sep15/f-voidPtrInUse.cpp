// hexDump.cpp
#include <iostream>
#include <iomanip>
using namespace std;

void hexDump(void* a, int n) {
   unsigned char* c = static_cast<unsigned char*>(a);
   cout << hex << setfill('0');
   for (int i = 0; i < n; i++)
      cout << setw(2) << static_cast<int>(c[i]) << " ";
   cout << dec << endl;
}

int main() {
   int i = 2456;
   double x = 4.56;
   cout << "Integer: "; hexDump(&i, sizeof(int));
   cout << "Double: ";  hexDump(&x, sizeof(double));
   return 0;
}