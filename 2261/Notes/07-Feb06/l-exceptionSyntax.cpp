#include <iostream>
using namespace std;

int main() {
   try {
      // code that may throw
   }
   catch (Type1 id) {
      // handler for Type1
   }
   catch (Type2 id) {
      // handler for Type2
   }
   catch (Type3 id) {
      // handler for Type2
   }
   catch (...) {
      // handler for everything else
   }
   return 0;
}
// terminate if exception is not handled.