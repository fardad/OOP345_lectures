#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using clk = std::chrono::steady_clock;
int main() {
   auto Seconds = clk::now() + chrono::seconds(1);
   int tx, ty, tz;
   std::thread tX = std::thread([&]() {for (tx = 0; clk::now() < Seconds; cout << '^', tx++); });
   std::thread tY = std::thread([&]() {for (ty = 0; clk::now() < Seconds; cout << '_', ty++); });
   std::thread tZ = std::thread([&]() {for (tz = 0; clk::now() < Seconds; cout << '-', tz++); });
   tX.join();
   tY.join();
   tZ.join();
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "tZ printed " << tz << " characters!" << endl;
   return 0;
}
