#include <iostream>
using namespace std;

class Num {
   int value;
   static int s;
public:
   Num(int val=0) :value{ val } {
      s++;
      cout << "Object Number " << s << " is created!" << endl;
   }
   void print() {
      cout << noOfInstances() <<": " << value << endl;
   }
   static int noOfInstances() {  // class function class method
      return s;
   }
   ~Num() {
      s--;
   }
};
int Num::s = 0;
void foo() {
   Num n[10];
   cout << Num::noOfInstances() << endl;
}

int main() {
   Num N(10), M(20);
   foo();
   N.print();
   M.print();
   cout << N.noOfInstances() << endl;
   return 0;
}