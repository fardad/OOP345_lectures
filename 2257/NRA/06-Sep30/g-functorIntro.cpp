#include <iostream>
using namespace std;
// functor
class Sum {
   size_t no{ };
public:
   int operator()(int left, int right) {
      no++;
      return left + right;
   }
   operator size_t()const {
      return no;
   }
};

int main() {
   Sum sum;
   int a, b=20;
   a = sum(b, 10);
   cout << a << endl;
   a = sum(b, 10);
   cout << a << endl;
   a = sum(b, 10);
   cout << a << endl;
   a = sum(b, 10);
   cout << a << endl;
   cout << "Number of calls: " << size_t(sum) << endl;

   return 0;
}