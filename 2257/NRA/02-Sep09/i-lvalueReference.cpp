// reference.cpp
#include <iostream>
using namespace std;

int main() {
   int x = 5;
   int& ref = x; // ref is another name for x

   ref = 10; // changes x too
   cout << "x = " << x << endl;
   return 0;
}