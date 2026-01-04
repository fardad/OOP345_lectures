#include <iostream>
using namespace std;
/*
[capture-list](params) -> return-type {
    // body
}

*/

int main() {
   auto hello = []() {cout << "Hello!" << endl; };
   auto dblIt = [](int val) {return 2 * val; };
   hello();

   cout << dblIt(30) << endl;

   return 0;
}