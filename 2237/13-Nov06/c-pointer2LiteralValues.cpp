#include <iostream>

using namespace std;
int main() {
   char name[] = "Fred";
   const char* p = "John";
   cout << *name << endl;
   cout << *(name + 2) << endl;
   cout << p << endl;
   *name = 'X';
   return 0;
}