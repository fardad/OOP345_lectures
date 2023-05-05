#include <iostream>
using namespace std;
class Add {
  
public:
   int operator()(int a, int b) {
      return a + b;
   }
};
int main() {
   []  (int l) {for (int i = 0; i < l; cout << '-', i++); cout << endl; }(30); // lambda expression
   auto line = [](int l) {for (int i = 0; i < l; cout << '-', i++); cout << endl; };
   line(50);
   return 0;
}