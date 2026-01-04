#include <iostream>
using namespace std;
void sum(int a, int b) {
   cout << (a + b) << endl;
}
void prod(int a, int b) {
   cout << (a * b) << endl;
}
void repeat(int num, int val) {
   for (int i = 0; i < num; i++) {
      if (i) cout << ", ";
      cout << val;
   }
}
int main() {
   cout << "07-Sep29 OOP345 NBB" << endl;
   void (*funcPtr)(int, int);
   cout << reinterpret_cast<unsigned long long>(sum) << endl;
   cout << reinterpret_cast<unsigned long long>(prod) << endl;
   funcPtr = sum;
   funcPtr(10, 20);
   funcPtr = prod;
   funcPtr(10, 20);
   funcPtr = repeat;
   funcPtr(10, 20);

   return 0;
}
