// Functional - function wrapper

#include <iostream>
#include <functional>
using namespace std;
// a simple function
long multiply(long x, long y) {
   return x * y;
}

// a functor
struct Multiply {
   long operator()(long x, long y) {
      return x * y;
   }
};

int main() {
   function<long(long, long)> f1 = multiply;
   function<long(long, long)> f2 = Multiply();
   function<long(long, long)> f3 = [](long x, long y) { return x * y; };
   cout << "f1(10, 2) = " << f1(10, 2) << endl;
   cout << "f2(10, 2) = " << f2(10, 2) << endl;
   cout << "f3(10, 2) = " << f3(10, 2) << endl;
   return 0;
}