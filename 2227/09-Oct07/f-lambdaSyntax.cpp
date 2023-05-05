#include <iostream>
using namespace std;

int main() {
   auto hello = []() {return "hello Lambda!"; };

   auto add10 = [](int i) {return i + 10; };


   cout << hello() << endl;

   cout << []() {for(int i = 0; i < 10; cout << i++ << endl);  return "Inline Lambda!"; }() << endl;

   cout << add10(100) << endl;

   return 0;
}