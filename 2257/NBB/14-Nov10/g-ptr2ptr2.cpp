#include <iostream>
using namespace std;
void addOne(int* p) {
   (*p)++;
}
void advance(int** p) {
   (*p)++;
}



int main() {

   int a[3] = { 10, 20, 30 };
   int* ptr = a;
   ++ptr;
   cout << *ptr << endl;
   addOne(ptr);
   cout << *ptr << endl;
   advance(&ptr);
   cout << *ptr << endl;
   return 0;
}