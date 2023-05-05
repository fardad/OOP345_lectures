#include <iostream>
#include <thread>
using namespace std;

void threads() {
   int c{}, d{}, p{};
   cout << "===================================================================" << endl;
   thread tc([&]() {for (c = 0; c < 30; cout << '^', c++); });
   thread td([&]() {for (d = 0; d < 40; cout << '-', d++); });
   thread tp([&]() {for (p = 0; p < 50; cout << '^', p++); });
   tc.join();
   td.join();
   tp.join();
   cout << endl << "===================================================================" << endl;
   cout << "tc printed:  " << c << endl;
   cout << "td printed:  " << d << endl;
   cout << "tp printed:  " << p << endl;
}
int main() {
   threads();
   return 0;
}