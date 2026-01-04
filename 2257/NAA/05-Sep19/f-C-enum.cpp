
#include <iostream>
#include <utility>
using namespace std;
//typedef int Weekday;
//const int sun = 0, mon = 1, tue = 2, wed=3, thu=4, fri=5, sat=6;
enum Weekday { sun , mon , tue, wed, thu, fri, sat };
// enum Weekday{sun=7, mon=1, tue, wed, thu, fri, sat};

int main() {
   Weekday w = sun;
   //....
   if (w == mon) {
      //whatever
   }
   return 0;
}