#include <iostream>
using namespace std;
int main() {

   auto hello = []() {
      return "Hello world!";
   };
   auto add4 = [](int i) { return i + 4; };
   auto sub4 = [](int i) { return i - 4; };



   cout << hello() << endl;

   [](char ch) {
      for (int i = 0; i < 10; i++) cout << ch;
      cout << endl;
   } ('=');

   cout << add4(10) << endl;
   cout << sub4(10) << endl;

   return 0;
}