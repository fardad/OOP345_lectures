// file: linkage_a.cpp
#include <iostream>
using namespace std;

static void display() { cout << "in module a\n"; }
void module_b(); // defined elsewhere

int main() {
   display();
   module_b();
   return 0;
}
// file: linkage_b.cpp
#include <iostream>
using namespace std;

static void display() { cout << "in module b\n"; }

void module_b() {
   display();
}