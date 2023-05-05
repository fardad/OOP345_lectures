#include <iostream>
using namespace std;
#include "foo.h"
namespace sdds {
   int tureGlobal = 10;
   void faa() {
      cout << "Faaing around!" << endl;
      foo();
   }
   void foo() {
      cout << "fooing around!" << endl;
   }
}