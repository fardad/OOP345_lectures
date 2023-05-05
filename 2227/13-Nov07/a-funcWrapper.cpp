#include <iostream>
#include <functional>
using namespace std;

long mul(int x, int y) {
   return long(x) * y;
}

class Multiply {
public:
   long operator()(int x, int y){
      return long(x) + y;
   }
};


int main() {
   function<long(int, int)> a = mul;
   function<long(int, int)> fa = Multiply();
   function<long(int, int)> la = [](int x, int y) {return long(x) * y; };

   cout << a(5, 10) << endl;
   cout << fa(20, 10) << endl;
   cout << la(3, 10) << endl;

   return 0;
}
