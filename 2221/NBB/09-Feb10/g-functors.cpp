#include <iostream>
using namespace std; 
class Add {
   int noc{}; // no of calls
public:
   int operator()(int a, int b) {
      noc++;
      return a + b;
   }
   int noOfCalls()const {
      return noc;
   }
};


auto main()->int {
   int a=0;
   Add add1, add2;
   cout << add1.noOfCalls() << endl;
   for (int i = 0; i < 10; i++) {
      a += add1(10, 30);
      cout << a << " ";
   }
   cout << endl << "no of calls: " << add1.noOfCalls() << endl;

   cout << a << " " << add2(100, 200) << endl;

   return 0;
}

