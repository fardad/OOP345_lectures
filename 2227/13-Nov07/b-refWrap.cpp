#include <iostream>
#include <functional>
using namespace std;


int main() {
   long l = 210L;
   reference_wrapper<long> L = l;
   cout << L << endl;
   L += 10;
   cout << L << endl;
   return 0;
}
