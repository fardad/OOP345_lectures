#include <iostream>
using namespace std;
class Foo {
public:
};
int main() {
   cout << "OOP345 NAA - May 26" << endl;
   int x = 10;          // x is an lvalue
   cout << x << endl;   // 'x' refers to a memory location

   int y = x + 5;       // (x + 5) is a prvalue
   cout << y << endl;

   int&& z = x + 5;     // result of (x + 5) materializes into an xvalue
   cout << z << endl;
   Foo F;
   Foo() = F;
   cout << "gone before this" << endl;
   return 0;
}