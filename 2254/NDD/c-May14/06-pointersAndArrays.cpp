
#include <iostream>
using namespace std;
struct T1 {
   char c;
   double d;
   int i;
};
int main( ) {
   int ar[5]{ 10, 20, 30, 40, 50 };
   cout << *ar << endl;
   *ar = 3000;
   cout << *ar << endl;
   cout << ar[0] << endl;
   cout << *&ar[0] << endl;
   cout << ar[3] << endl;
   cout << *(ar + 3) << endl;
   return 0;
}