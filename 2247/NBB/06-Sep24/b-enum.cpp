#include <iostream>
using namespace std;
//typedef int weekday;
//const int sun = 1;
//const int mon = 2;
//const int tue = 3;
//const int wed = 4;
//const int thu = 5;
//const int fri = 6;
//const int sat = 7;


//enum weekday { sun = 1, mon, tue, wed, thu, fri, sat }; //file scope constants
enum class weekday { sun = 1, mon, tue, wed, thu, fri, sat }; // class scope constants

// enum boolean{False = 0, True};

int main() {
   weekday wd = weekday::fri;
   if (wd == weekday::fri) {
      cout << "the day is friday that is " << int(weekday::fri) << endl;
   }
   return 0;
}
