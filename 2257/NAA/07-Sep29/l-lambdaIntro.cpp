#include <iostream>
using namespace std;
/*
[capture-list](params) -> return-type {
    // body
}

*/
int main() {
   auto hello = []() {
      return "Hello there!"; 
   };
   auto dblIt = [](int n) {return 2 * n; };
   cout << hello() << endl;
   cout << dblIt(100) << endl;
   return 0;
}