#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
struct foo1 {  // sorted descending to save space
   double a;
   double b;
   double c;
   int i;
   char ch;
   char filler[3]; // fills the fragment.
};
struct foo2 {  // not sorted occupies more space
   double a;
   char ch;
   double b;
   int i;
   double c;
};
int main() {
   cout << sizeof(foo1) << endl;
   cout << sizeof(foo2) << endl;
   std::cout << alignof(int) << std::endl;
   std::cout << alignof(double) << std::endl;
   return 0;
}