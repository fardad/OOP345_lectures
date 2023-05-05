#include <iostream>
using namespace std;
#define sum(x,y) (x+y) // search for sum replace with a+b

int main() {
   int a = 10;
   int b = 20;
   double d = 2.2;
   double e = 3.3;
   cout << sum(a,b) * 2 << endl;
   cout << sum(d,e) * 2 << endl;
   return 0;
}
/*
//walk through number one's output is a C++ program:

int main() {
   int a = 10;
   int b = 30;
   double d = 2.2;
   double e = 3.3;
   cout << (a + b) * 2<< endl;
   cout << (d + e) * 2<< endl;
   return 0;
}
//walk through number two is the actual execution output
*/
