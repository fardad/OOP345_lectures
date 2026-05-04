#include <iostream>
#include <functional>
using namespace std;
// A simple free function
long add_values(long x, long y) { return x + y; }

// A functor (function object)
struct Adder {
   long operator()(long x, long y) { return x + y; }
};

void compute_and_print(const std::function<long(long, long)>& func, long a, long b) {
   cout << "Operator result of " << a << " and " << b << " will be " << func(a, b) << endl;
}

int main() {
   cout << "OOP345 NBB - Mar02" << endl;
   std::function<long(long, long)> f1 = add_values;
   std::function<long(long, long)> f2 = Adder();
   std::function<long(long, long)> f3 = [](long x, long y) { return x + y; };
   compute_and_print(f1, 10, 20);
   compute_and_print(f2, 10, 20);
   compute_and_print(f3, 10, 20);
   return 0;
}