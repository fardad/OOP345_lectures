// declarations.cpp
#include <iostream>
using namespace std;

extern int x;   // declaration (no definition yet)
int y = 10;     // definition (also a declaration)

void foo();     // function declaration (prototype)
void bar() {    // function definition
   cout << "bar()" << endl;
}