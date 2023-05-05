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
         if (i == 1) {
            throw str;
         }
         throw i;
      }
      catch (double de) {
         cout << "Double wad here: " << de << endl;
      }
      catch (const char* se) {
         cout << "Stirng was here: " << se << endl;
      }
      catch (...) {
         cout << "Something was thrown, I don't know what!!!" << endl;
      }
   }
   return 0;
}



