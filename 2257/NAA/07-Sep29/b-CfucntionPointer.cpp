#include <iostream>
using namespace std;
void sum(int a, int b) {
   cout << (a + b) << endl;
}
void prod(int a, int b) {
   cout << (a * b) << endl;
}
int main() {
   cout << "07-Sep29 OOP345 NAA" << endl;

   void (*funcPtr)(int, int);
   funcPtr = sum;
   cout << reinterpret_cast<unsigned long long>(sum) << endl;
   cout << reinterpret_cast<unsigned long long>(funcPtr) << endl;
   funcPtr(10, 20);
   funcPtr = prod;
   funcPtr(10, 20);
   (*funcPtr)(10, 20); // same as above but in C language
   return 0;
}

