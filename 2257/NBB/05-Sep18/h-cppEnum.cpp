
#include <iostream>
#include <utility>
using namespace std;

enum class Weekday { sun, mon, tue, wed, thu, fri, sat };


int main() {
   Weekday d;
   //....
   if (d == Weekday::thu) {
      // whatever
   }

   return 0;
}