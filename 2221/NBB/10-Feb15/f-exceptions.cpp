
#include <iostream>
using namespace std;

int main(void) {
   int i;
   double d = 4;
   char str[] = "hoohoo";
   for (i = 0; i < 3; i++) {
      try {
         if (i == 0) {
            throw d;
         }
         else if (i == 1) {
            throw str;
         }
         else {
            throw i;
         }
      }
      catch (double de) {
         cout << "Double d: " << d << endl;
      }
      catch (const char* s) {
         cout << "cstring str: " << s << endl;
      }
      catch (...) {
         cout << "something else!" << endl;
      }
   }
   return 0;
}