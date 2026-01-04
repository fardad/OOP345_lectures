#include <iostream>
#include <functional>
using namespace std;


int main() {
   long l = 210L;
   reference_wrapper<long> rw = l;
   cout << rw << endl;
   rw += 10;
   cout << rw << endl;
   return 0;
}
