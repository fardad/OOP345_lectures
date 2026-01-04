#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = chrono::steady_clock;
int main() {
   int tx, ty;
   auto Seconds = clk::now() + chrono::seconds(1);
   thread tX = thread([&]() {for (tx = 0; clk::now() < Seconds; cout << '^', tx++); });
   thread tY = thread([&]() {for (ty = 0; clk::now() < Seconds; cout << '_', ty++); });
   cout << "GO!" << endl;
   tX.join();
   tY.join();
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "tY Printed " << ty << " characters!" << endl;
   return 0;
}
