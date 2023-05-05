// Functional - reference wrapper

#include <iostream>
#include <functional>
using namespace std;
int main() {
   long v = 10L;
   reference_wrapper<long> R = v;
   long& ref = v;
   cout << "v = " << v << endl;
   R += 2;
   cout << "v = " << v << endl;
   return 0;
}