#include <iostream>
using namespace std;
class Add {
  
public:
   int operator()(int a, int b) {
      return a + b;
   }
};
int main() {
   int l = 30;
   auto lineW = [&]() {for (int i = 0; i < l; cout << '-', i++); cout << endl; l+=3; };
   auto lineR = [=]() {for (int i = 0; i < l; cout << '-', i++); cout << endl; /*error write no access: l+=3;*/ };
   lineR();
   lineW();
   lineW();
   lineW();
   lineW();
   return 0;
}