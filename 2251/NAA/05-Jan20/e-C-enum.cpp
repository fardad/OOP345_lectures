#include <iostream>
using namespace std;
enum week_day{sun=1, mon, tue, wed, thu, fri=10, sat };

int main( ) {
   week_day w;
   cout << wed << endl;
   w = wed;
   if ( w == wed ) {
      cout << "it is wednesday!" << endl;
   }
   return 0;
}