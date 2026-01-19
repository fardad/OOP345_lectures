#include <iostream>
using namespace std;
void prnName(const char* name) {
   cout << name << endl;
   cout << "sizeof name in function: " << sizeof(name) << endl;

}
int main() {
   char name[50] = "Fardad";
   int a[6] = { 10, 20, 30, 40, 50, 60 };
   char* cp = name;
   int* ip = a;
   cout << *ip << *cp << endl;
   if (sizeof(ip) == sizeof(cp)) {
      cout << "same" << endl;
   }
   else {
      cout << "different" << endl;
   }
   cout << "sizeof name: " << sizeof(name) << endl;
   cout << "sizeof cp: " << sizeof(cp) << endl;
   cout << "sizeof a: " << sizeof(a) << endl;
   cout << "sizeof ip: " << sizeof(ip) << endl;
   prnName(name); // prnName(const char* name = main::name);
   return 0;
}