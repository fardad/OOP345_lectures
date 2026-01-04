#include <iostream>
using namespace std;

void advance(int*& p) {
   p++;
}
void advance(int** p) {
   (*p)++;
}

int main() {
   int a[4] = { 10, 20, 30, 40 };
   int* ptr = a;
   cout << *ptr << endl;
   ++ptr;
   cout << *ptr << endl;
   advance(ptr);
   cout << *ptr << endl;
   advance(&ptr);
   cout << *ptr << endl;
   return 0;
}