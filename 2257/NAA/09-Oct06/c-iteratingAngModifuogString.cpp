// string_iter.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
   string msg = "Seneca";
   for (char& ch : msg) {
      ch = toupper(ch);
   }
   cout << msg << endl;
   return 0;
}