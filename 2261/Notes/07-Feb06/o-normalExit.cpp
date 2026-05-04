// file: exit.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

void exit_1() {
   cerr << "In exit_1\n";
}

int main() {
   int i;
   cout << "Return(!=1), Exit(1) ? ";
   cin >> i;

   if (i == 1) {
      atexit(exit_1);
      exit(1);
   }
   return i;
}