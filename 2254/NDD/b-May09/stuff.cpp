
namespace {
   void foo() {

      //whatever

   }
}
// foo is only accessible here and not in other files
int globalVar = 10;  // static duration

void counter() {
   static int count = 0;  // also static
   ++count;
}