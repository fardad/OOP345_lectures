#include <iostream>
using namespace std;
class Add {
public:
   int operator()(int a, int b) {
      return a + b;
   }
};

int main() {
   Add a;
   int x = 10, y = 20;
   int sum = a(x, y);
   cout << "Sum: " << sum << endl;
   return 0;
}