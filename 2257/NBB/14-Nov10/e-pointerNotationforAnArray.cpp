#include <iostream>
using namespace std;

int main() {
   int a[3][4] = {
      {1,2,3,4},
      {10,20,30,40},
      {100,200, 300,400}
   };
   int* ptr = reinterpret_cast<int*>(a);
   cout << ptr[0] << endl;
   cout << a[0][0] << endl;
   cout << ptr[3] << endl;
   cout << a[0][3] << endl;
   cout << ptr[4] << endl;
   cout << a[0][5] << endl;
   cout << a[1][5] << endl;
   cout << *(a + 1)[0] << endl;
   cout << **(a + 1) << endl;
   cout << *(*(a + 1)+2) << endl;
   return 0;
}