// file: capture_by_reference.cpp
#include <iostream>
using namespace std;

template<typename Func>
int sub(int i, Func func) { return func(i); }

int main() {
   int k = 4;
   cout << sub(10, [&](int i) { return i - k++; }) << endl;
   cout << "k = " << k << endl;
   return 0;
}