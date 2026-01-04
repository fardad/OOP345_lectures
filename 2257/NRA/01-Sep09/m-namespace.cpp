// dot.h
namespace dot {
   const int ML = 5;
   const char* leader(char*);
}

// dot.cpp
#include "dot.h"
namespace dot {
   const char* leader(char* s) {
      for (int i = 0; i < ML; i++) s[i] = '.';
      s[ML] = '\0';
      return s;
   }
}

// main.cpp
#include <iostream>
#include "dot.h"
using namespace std;
using dot::leader;

int main() {
   char s[10];
   cout << leader(s) << endl;
}