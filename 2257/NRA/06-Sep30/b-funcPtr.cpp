#include <iostream>
using namespace std;
void sum(int a, int b) {
   cout << (a + b) << endl;
}
void prod(int a, int b) {
   cout << (a * b) << endl;
}
void rep(int num, int val) {
   for (int i = 0; i < num; i++) {
      if (i != 0) cout << ", ";
      cout << num;
   }
   cout << endl;
}

int main() {
   cout << "06-Sep30 OOP345 NRA" << endl;
   void (*funcPtr)(int, int);
   funcPtr = sum;
   cout << sum << endl;
   cout << reinterpret_cast<unsigned long long>(sum) << endl;
   cout << reinterpret_cast<unsigned long long>(funcPtr) << endl;

   funcPtr(10, 20);
   funcPtr = prod;
   funcPtr(10, 20);
   funcPtr = rep;
   funcPtr(10, 20);

   return 0;
}
