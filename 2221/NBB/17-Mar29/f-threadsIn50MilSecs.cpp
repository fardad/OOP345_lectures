#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using clk = std::chrono::steady_clock;
int main() {
   auto msecs = clk::now() + chrono::milliseconds(50);
   int c{}, d{}, p{};
   cout << "===================================================================" << endl;
   thread tc([&]() {for (c = 0; clk::now() < msecs; cout << '^', c++); });
   thread td([&]() {for (d = 0; clk::now() < msecs; cout << '-', d++); });
   thread tp([&]() {for (p = 0; clk::now() < msecs; cout << '+', p++); });
   tc.join();
   td.join();
   tp.join();
   cout << endl << "===================================================================" << endl;
   cout << "tc printed:  " << c << endl;
   cout << "td printed:  " << d << endl;
   cout << "tp printed:  " << p << endl;
   cout << "Total: " << c + d + p << endl;
   return 0;
}