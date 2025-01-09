#include <stack>
#include <iostream>
using namespace std;
int main() {
   int a[10] = { 10, 20, 30, 40, 50, 60, 70, 80 ,90, 100 };
   int* p = &a[0];
   p++;
   cout << *p << " " << p << endl;
   return 0;
}