// static Review
#include <iostream>
using namespace std;

static int filescopeVariable = 0;

void foo() {
   static int var{};
   var++;
   cout << var << endl;
}
int main() {
   foo();
   foo();
   foo();
   return 0;
}