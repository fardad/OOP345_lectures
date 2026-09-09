#include <iostream>
using namespace std;
/*
try {
    // code that may throw
}
catch (Type1 id) {
    // handler for Type1
}
catch (Type2 id) {
    // handler for Type2
}
catch (...) {
    // handler for everything else
}



*/
void f1() {
   cout << "f1" << endl;
   throw double(5.3);
}
void f2() {
   cout << "f2" << endl;
   f1();
}
void f3() {
   cout << "f3" << endl;
   f2();
}
int main() {
   std::cout << "OOP345 NAA - Jun03" << endl;
   int i;
   char str[] = "hoohoo";
   for (i = 0; i < 3; i++) {
      try {
         if (i == 0) {
            f3();
         }
         if (i == 1) {
            throw str;
         }
         throw i;
         cout << "this will never happen!" << endl;
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