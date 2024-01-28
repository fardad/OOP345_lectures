#include <iostream>
using namespace std;
auto isAdult(int value) -> bool {
   return (value >= 18 && value <= 65);
}

auto getInt()->int {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if(cin.fail()) {
         cin.clear();
         cout << "Invlid integer, try again: ";
      } else {
         if(isAdult(num) ){
            done = true;
         } else {
            cout << "invlid age, try again: ";
         }
      }
      cin.ignore(10000, '\n');
   } while(!done);
   return num;
}
auto main() -> int {
   int a[50];
   // what is in a?
   int x;
   int* p = &x;
   cout << unsigned(p) << endl;
   cout << unsigned(a) << endl;
   cout << unsigned(getInt) << endl;
   return 0;
}
