// Module_a.cpp
#include <iostream>
using namespace std;
extern int share_me; // declaration

void display() {
   cout << "Module A: " << share_me++ << endl;
}

// Module_b.cpp
#include <iostream>
using namespace std;
int share_me = 0; // definition
void display();

int main() {
   display();
   display();
   cout << "Module B: " << share_me << endl;
}