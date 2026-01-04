
#include <iostream>
#include <utility>
using namespace std;
enum class Weekday { sun, mon, tue, wed, thu, fri, sat };

int main() {
   Weekday w = Weekday::sun;
   //....
   if (w == Weekday::mon) {
      //whatever
   }
   return 0;
}