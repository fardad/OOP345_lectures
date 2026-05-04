#include <iostream>
using namespace std;


const int& getInt() {
   static int a{};
   cin >> a;
   return a;
}

int& badGetInt() {
   static int a{};
   cin >> a;
   return a;
}
int main() {
   cout << "OOP345 JAN12" << endl;
   int val;
   cout << "int: ";
   val = getInt();
   int& r = badGetInt();
   r = 234; // badGetInt's a will change

   return 0;
}