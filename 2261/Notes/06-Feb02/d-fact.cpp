#include <iostream>
using namespace std;
void module(); // external linkage 
extern int external; // defined somewhere else

unsigned factor(unsigned n) {
   if (n <= 2u) {
      return n;
   }
   else {
      return factor(n - 1) * n;
   }
}


auto main()->int {
   cout << "OOP345 NBB - Feb 02" << endl;
   cout << factor(5) << endl;
   return 0;
}

