#include <iostream>

using namespace std;
// fact (3)    == 1 * 2 * 3
constexpr long long fact(long long n) {
   return (n <= 1) ? 1 : n * fact(n - 1);
}

constexpr long long f20 = fact(20);


int main() {
   cout << "calculated at compile time: " << f20 << endl;
   cout << "calcualted at run time: " << fact(20) << endl;
   static_assert(sizeof(void*) == 8, "64 bit architecture is needed for this application");
   return 0;
}
