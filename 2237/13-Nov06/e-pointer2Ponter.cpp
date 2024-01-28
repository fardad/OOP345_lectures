#include <iostream>
void addone(int* ap) {
   (*ap)++;
}
void addone(char** pp) {
   (*pp)++;
}
using namespace std;
int main() {
   int a = 20;
   char name[21] = "Homer";
   char* p = name;
   p++;
   cout << *p << endl;
   cout << p << endl;
   cout << a << endl;
   addone(&a);
   cout << a << endl;
   addone(&p);
   cout << *p << endl;
   return 0;
}