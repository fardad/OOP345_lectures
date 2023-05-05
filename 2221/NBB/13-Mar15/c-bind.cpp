#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int bar(char fill, int len) {
   for (int i = 0; i < len; i++, cout << fill);
   cout << endl;
   return len;
}

struct Bar {
   int operator() (char fill, int len) {
      for (int i = 0; i < len; i++, cout << fill);
      cout << endl;
      return len;
   }
};


int main() {
   function<int(char, int)> f1 = bar;
   function<int(char, int)> f2 = Bar();
   function<int(char, int)> f3 = [](char fill, int len) {
      for (int i = 0; i < len; i++, cout << fill);
      cout << endl;
      return len;
   };

   cout << f1('1', 10) << endl;
   cout << f2('2', 20) << endl;
   cout << f3('3', 30) << endl;

   auto line = bind(bar, '-', 60);

   line();

   return 0;
}