// function_wrapper.cpp
#include <iostream>
#include <functional>

// A simple free function
long add_values(long x, long y) { return x + y; }

// A functor (function object)
struct Adder {
   long operator()(long x, long y) { return x + y; }
};

// Caller function that accepts a uniform std::function wrapper
void compute_and_print(const std::function<long(long, long)>& op, long a, long b) {
   std::cout << "Result of operation(" << a << ", " << b << ") = " << op(a, b) << std::endl;
}

int main() {
   // Wrap the free function
   std::function<long(long, long)> f1 = add_values;
   // Wrap the functor
   std::function<long(long, long)> f2 = Adder();
   // Wrap the lambda
   std::function<long(long, long)> f3 = [](long x, long y) { return x + y; };

   // Pass all three wrapped versions to the caller function uniformly
   compute_and_print(f1, 15, 7);
   compute_and_print(f2, 15, 7);
   compute_and_print(f3, 15, 7);
   compute_and_print([](long a, long b) {return ++a + ++b; }, 10, 30);
   return 0;
}