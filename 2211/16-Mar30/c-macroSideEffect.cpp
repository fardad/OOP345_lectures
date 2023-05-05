
#include <iostream>
using namespace std;


#define square(a) ((a)*(a))

int main() {
   int x = 10;
   int y = square(x);
   cout << x << "^2 = " << y << endl;
   y = square(++x);// careful!!!!
   cout << x << "^2 = " << y << endl;
   return 0;
}