#include <iostream>
using namespace std;
void setToZero(int* val) {
   *val = 0;
}
void setToZero(int& val) {
   val = 0;
}

int main() {
   int a = 10, b = 20;
   setToZero(&a);
   setToZero(b);

   cout << a << endl;
   cout << b << endl;

   return 0;


}