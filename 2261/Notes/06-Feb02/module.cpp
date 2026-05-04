#include <iostream>
using namespace std;

static int internal{};
int exernal{};
static void display() { // only be used in this module, hence internal linkage
   cout << "in module b\n"; 
}

void module() {
   display();
}