#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
using namespace std;
using clk = std::chrono::steady_clock;
int main() {
   int tx, ty;
   auto Seconds = clk::now() + chrono::seconds(1);
   std::mutex key;
   key.lock();
   std::thread tX = std::thread([&]() {
      std::scoped_lock<std::mutex> sl(key);
      for (tx = 0; clk::now() < Seconds; cout << '^', tx++);
      Seconds = clk::now() + chrono::seconds(1);
   });
   std::thread tY = std::thread([&]() {
      std::scoped_lock<std::mutex> sl(key);
      for (ty = 0; clk::now() < Seconds; cout << '_', ty++);
      Seconds = clk::now() + chrono::seconds(1);
   });
   cout << "GO!" << endl;
   key.unlock();
   tX.join();
   tY.join();
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "ty Printed " << ty << " characters!" << endl;
   return 0;
}
