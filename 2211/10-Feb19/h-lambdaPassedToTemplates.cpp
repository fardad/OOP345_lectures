#include <iostream>
using namespace std;
template<typename Func>
int add(int i, Func func) {
   return func(i);
}

template<typename Func>
int sub(int i, Func func) {
   return func(i);
}

int main() {
   int k = 4;
   auto iPlusKPlusPlus = [&](int i) { return i + k++; };
   cout << add(10, iPlusKPlusPlus) << endl;
   cout << "k = " << k << endl;
   cout << sub(10, [&](int i) { return i - k++; }) << endl;
   cout << "k = " << k << endl;
}