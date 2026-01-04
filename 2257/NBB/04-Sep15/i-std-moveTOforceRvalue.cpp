// std_move.cpp
#include <iostream>
#include <utility>
using namespace std;

void print(const int& n) { cout << "lvalue: " << n << endl; }
void print(int&& n) { cout << "rvalue: " << n << endl; }

int main() {
   int x = 10;
   print(x);
   print(std::move(x)); // forces rvalue reference
   return 0;
}