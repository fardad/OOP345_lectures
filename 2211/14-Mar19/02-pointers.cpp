#include <iostream>
/*
* comes after type: pointer
* comes before a pointer variable: Target Of
* comes between two variables: multiplication

*/

using namespace std;
int main() {
   char name[50] = "Fardad";
   const char* a = "Joe";
   char b[] = "Jow";
   int a[6] = { 20, 30, 40, 50, 60 };
   int v[100] = { 0 };
   cout << *a << endl;
   cout << *(a + 2) << endl;
   // a[0]  the same as *(a + 0)
   cout << *(a + 20) << endl;
   char ch;
   for (int i = 0; i < 6; i++) {
      ch = "Fardad"[i];
      cout << ch << endl;
   }
   return 0;
}