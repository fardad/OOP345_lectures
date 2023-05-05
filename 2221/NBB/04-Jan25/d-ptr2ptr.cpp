#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
void setTen(int* val) {
   *val = 10;
}
void setTen(int& val) {
   val = 10;
}
void anotherchange(char**** ptr) {
   ***ptr; // is name
   **ptr;  // des
   *ptr;  //ptr in change
   ptr; //is the local variable ptr
}
void change(char*** ptr) {
   **ptr; // is name
   *ptr;  // des
   ptr;  //is the local variable ptr
   anotherchange(&ptr);
}
void dynCopy(char** des, const char* src) {
   delete[] *des;
   *des = new char[strlen(src) + 1];
   strcpy(*des, src);
   change(&des);
}

void dynCopy(char*& des, const char* src) {
   delete[] des;
   des = new char[strlen(src) + 1];
   strcpy(des, src);
}


int main() {
   int a, b;
   setTen(&a);
   cout << a << endl;
   setTen(b);
   cout << b << endl;
   char* name = new char[5];
   strcpy(name, "Fred");
   cout << name << endl;
   dynCopy(&name, "Fardad");
   cout << name << endl;
   dynCopy(name, "Passing the refernce");
   cout << name << endl;
   delete[] name;
   return 0;
}