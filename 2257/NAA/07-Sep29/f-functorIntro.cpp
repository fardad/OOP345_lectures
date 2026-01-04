#include <iostream>
using namespace std;
// functor
class Add {
   int no{0};
public:
   int operator()(int num1, int num2) {
      no++;
      return num1 + num2;
   }
   operator int()const {
      return no;
   }
};


int main() {
   Add add;
   cout << int(add) << endl;
   cout << add(10, 20) << endl;
   cout << add(10, 20) << endl;
   cout << add(10, 20) << endl;
   cout << add(10, 20) << endl;
   cout << add(10, 20) << endl;
   cout << add(10, 20) << endl;
   cout << int(add) << endl;
   return 0;
}