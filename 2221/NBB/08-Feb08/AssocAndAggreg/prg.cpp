#include <iostream>
#include "Library.h"
#include "Book.h"
using namespace std;
using namespace sdds;
template <typename T>
void show(T p, const char* prompt) {
   cout << prompt << endl;
   cout << "---------------------" << endl;
   do {
      cout << (**p) << endl;
   } while (*(++p));
   cout << "---------------------" << endl;
}

int main() {
   Library
      V("Vaughan"),
      T("Toronto"),
      Y("Yorkdale");
   Book
      C("C Reference", 123),
      CPP("CPP Programming", 234),
      CP("Crime and Punishment", 345),
      H("Harry Potter", 456),
      F("Fox in Socks", 567),
      G("Green Eggs and Ham", 678);
   Library* l[4] = { &V, &T, &Y }; // null terminated array of Library pointers
   Book* b[7] = { &C, &CPP, &CP, &H, &F, &G }; // null terminated array of Book pointers
   show(l, "Library list");
   show(b, "Book list");
   V << C << CP << F;
   T << CPP << C << G;
   Y << CP << H << G << F;
   show(l, "Library list");
   show(b, "Book list");
   return 0;
}