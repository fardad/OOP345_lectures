// bool.cpp
#include <iostream>
using namespace std;

int main() {
   bool flag = true;
   cout << "flag: " << flag << endl; // prints 1
   flag = false;
   cout << "flag: " << flag << endl; // prints 0
   flag = 1.234;
   cout << "flag: " << flag << endl; // prints 0

   return 0;
}