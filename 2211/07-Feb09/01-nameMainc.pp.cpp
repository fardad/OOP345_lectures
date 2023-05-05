#include <iostream>
#include "Name.h"
using namespace sdds;
using namespace std;

int main() {
   Name A;

   A.addToName("Home").addToName(" ").addToName("Jay")
      .addToName(" ").addToName("Simpson").print() << endl;

   return 0;
}