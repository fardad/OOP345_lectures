#include <iostream>
#include <fstream>
using namespace std;
void print(const char* ptr) {
   cout << ptr << endl;
}

void move(char** P) {
   while (**P && **P != ' ') {
      (*P)++;
   }
}

void move(char*& P) {
   while (*P && *P != ' ') {
      P++;
   }
}

int main() {
   char cstr[] = "This is a test and I want to check for spaces in it.";
   char* ptr = cstr;
   cout << ptr << endl;
   ptr++;
   move(&ptr);
   cout << ptr << endl;
   ptr++;
   move(&ptr);
   cout << ptr << endl;
   ptr++;
   move(&ptr);
   cout << ptr << endl;
   return 0;
}