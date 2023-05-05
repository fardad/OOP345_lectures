#include <iostream>
using namespace std;

void show(int**** p4) {
   cout << ****p4 << endl;
}


void show(int*** p3) {
   show(&p3);
}

void show(int** p2) {
   show(&p2);
}

void show(int* p1) {
   show(&p1);
}

int main() {
   int p{ 34 };
   show(&p);
   return 0;
}
