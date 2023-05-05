
#include <iostream>
using namespace std;


#define badadd(a,b) a+b 
#define add(a,b) ((a)+(b)) 

#define max(a, b) (((a)>(b))?(a):(b))

int main() {
   int a, b = 1, c = 2;
   a = add(b, c)*3;
   // a = b + c *3;
   // a = 1 + 2 * 3
   a = add(b, c + 3);
   cout << a << endl;
   return 0;
}