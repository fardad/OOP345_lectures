#include <iostream>
using namespace std;
#ifdef max
#undef max
#endif
#define max(x,y) ((x)>(y)?(x):(y))  // this will be a redefine if max is already defined with no error

template<typename T>
T maximum(T a, T b) {
   return a > b ? b : a;
}


int main() {
   int a = 10;
   int b = 20;
   double d = 2.2;
   double e = 3.3;
   cout << max(d, e) << endl;
   cout << max(d, e) << endl;
   cout << max(d, e) << endl;
   cout << max(d, e) << endl;
   cout << max(d, e) << endl;
   cout << maximum(d, e) << endl;
   cout << maximum(d, e) << endl;
   cout << maximum(d, e) << endl;
   cout << maximum(d, e) << endl;
   cout << maximum(d, e) << endl;
   return 0;
}

