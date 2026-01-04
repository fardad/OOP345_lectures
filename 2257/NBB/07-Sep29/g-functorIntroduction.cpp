#include <iostream>
using namespace std;
// Functors or Function Objects;
class Add {
   int no{ 0 };
public:
   operator int()const {
      return no;
   }
   int operator()(int num1, int num2) {
      no++;
      return num1 + num2;
   }
};
int main() {
   Add add;
   cout << int(add) << endl;

   cout << "call operator returns: " << add(10, 30) << endl;
   cout << "call operator returns: " << add(10, 30) << endl;
   cout << "call operator returns: " << add(10, 30) << endl;
   cout << "call operator returns: " << add(10, 30) << endl;
   cout << "call operator returns: " << add(10, 30) << endl;
   cout << "call operator returns: " << add(10, 30) << endl;
   cout << "Add was called  " << int(add) << " times" << endl;
   return 0;
}