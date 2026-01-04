// move_example.cpp
#include <iostream>
#include <utility>
using namespace std;
static int mustBeFileScopeOnly = 123;

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
