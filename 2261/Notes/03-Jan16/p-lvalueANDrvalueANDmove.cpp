#include <iostream>
struct Int {
   int m_val{};
   Int(int val) :m_val{ val } {};
};

using namespace std;

void print(const int& n) {
   cout << "lvalue: " << n << endl;
}
void print(int&& n) {
   cout << "rvalue: " << n << endl;
}

void print(const Int& n) {
   cout << "Int lvalue: " << n.m_val << endl;
}
void print(Int&& n) {
   cout << "Int rvalue: " << n.m_val << endl;
}


int main() {
   cout << "OOP345NBB - Jan 16" << endl;

   int a = 10;

   Int I = 10;

   print(a);
   print(100);
   print(I);
   print(Int(2000));
   print(move(a));
 


   return 0;
}