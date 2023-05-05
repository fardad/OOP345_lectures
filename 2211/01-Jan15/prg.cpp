#include <iostream>
using namespace std;
struct Container {
   int val;
   static int sval;
   Container() {
      val = 0;
      sval++;
   }
   void print() {
      cout << "val: " << val << endl << "sval: " << sval << endl;
   }
};

int Container::sval = 0;

int main() {
   Container A, B , C;
   cout << A.sval << endl;
   cout << Container::sval << endl;
   A.sval = 50;
   cout << A.sval << endl;
   cout << B.sval << endl;
   cout << C.sval << endl;
   cout << Container::sval << endl;

   return 0;
}