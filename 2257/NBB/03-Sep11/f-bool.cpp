// bool.cpp
#include <iostream>
using namespace std;

int main() {
   bool flag = true;
   cout << "flag: " << flag << endl; // prints 1
   flag = false;
   cout << "flag: " << flag << endl; // prints 0
   flag = 32;
   cout << "flag: " << flag << endl; // prints 1

   return 0;
}