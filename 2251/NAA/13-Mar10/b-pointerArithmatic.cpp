#include <iostream>
using namespace std;
int main() {
   char name[50] = "Fardad";
   int a[6] = { 10, 20, 30, 40, 50, 60 };
   char* cp = name;
   int* ip = a;
   cout << cp[3] << endl;
   cout << *(cp + 3) << endl;
   cout << reinterpret_cast<size_t>(cp) << endl;
   cout << reinterpret_cast<size_t>(&cp[3]) << endl;
   cout << reinterpret_cast<size_t>(cp + 3) << endl;
   cout << "---------------------------" << endl;
   cout << reinterpret_cast<size_t>(a) << endl;
   cout << reinterpret_cast<size_t>(&a[3]) << endl;
   cout << reinterpret_cast<size_t>(a + 3) << endl;
   return 0;
}
