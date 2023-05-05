#include <iostream>
using namespace std;
class Add {
  
public:
   int operator()(int a, int b) {
      return a + b;
   }
};
int main() {
   Add foo;
   cout << foo(10, 50) << endl;
   return 0;
}