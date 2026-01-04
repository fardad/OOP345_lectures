// class_static.cpp
#include <iostream>
using namespace std;
enum Weekday{sun, mon, tue, wed, thu, fri, sat};


int main() {
   Weekday w;
   //...
   if (w == mon) {
      cout << "start working" << endl;
   }
   return 0;
}