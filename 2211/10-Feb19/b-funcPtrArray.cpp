#include <iostream>
using namespace std;

void add(int a, int b) {
   cout << a << "+" << b << "=" << (a + b) << endl;
}
void sub(int a, int b) {
   cout << a << "-" << b << "=" << (a - b) << endl;
}
void mul(int a, int b) {
   cout << a << "x" << b << "=" << (a * b) << endl;

}
void divid(int a, int b) {
   cout << a << "/" << b << "=" << (a / b) << endl;
}

int main() {
   void (*func[4])(int, int) = { add, sub, mul, divid };
   for (int i = 0; i < 4; i++) {
      func[i](10, 2);
   }
   return 0;
}