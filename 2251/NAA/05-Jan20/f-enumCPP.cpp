#include <iostream>
using namespace std;
enum class Week_day{sun=1, mon, tue, wed, thu, fri, sat };
ostream& operator<<(ostream& ostr, const Week_day& wd){
   switch ( wd ) {
   case Week_day::sun:
      ostr << "Sunday";
      break;
   case Week_day::mon:
      ostr << "Monday";
      break;
   case Week_day::tue:
      ostr << "Tuesday";
      break;
   case Week_day::wed:
      ostr << "Wednesday";
      break;
   case Week_day::thu:
      ostr << "Thursday";
      break;
   case Week_day::fri:
      ostr << "Friday";
      break;
   case Week_day::sat:
      ostr << "Saturday";
      break;
      return ostr;
   }


}

int main( ) {
   Week_day w = Week_day::sat;
   cout << w << endl;
   return 0;
}