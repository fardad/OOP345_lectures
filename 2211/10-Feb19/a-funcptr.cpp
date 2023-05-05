#include <iostream>
using namespace std;
void add(int a, int b) {
   cout << a << "+" << b << "=" << (a + b) << endl;
}

int main() {
   void (*funcPtr)(int, int) = add;
   (*funcPtr)(10, 2); // C
   funcPtr(10, 2); // C++
   return 0;
}