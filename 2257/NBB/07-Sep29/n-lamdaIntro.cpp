
#include <iostream>
using namespace std;


int main() {
   auto hello = 
      []() { 
         return "Hello there!";
      };
   auto dblIt = [](int n) {return n * 2; };

   cout << hello() << endl;
   cout << dblIt(500) << endl;
   return 0;
}