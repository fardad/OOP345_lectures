// hexDump.cpp
#include <iostream>
#include <iomanip>
using namespace std;

void hexDump(void* a, size_t n) {
   unsigned char* c = static_cast<unsigned char*>(a);
   cout << hex << setfill('0');
   for (size_t i = 0; i < n; i++)
      cout << setw(2) << static_cast<int>(c[i]) << " ";
   cout << dec << endl;
}

int main() {
   int i = 20;
   double x = 4.56;
   cout << "Integer: "; hexDump(&i, sizeof(i));
   cout << "Double: ";  hexDump(&x, sizeof(x));
   return 0;
}