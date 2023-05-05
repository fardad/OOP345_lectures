#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
int main() {
   int tx, ty, tz;
   std::atomic<int> counter = 0;
//   auto chars = [&](char ch) {for (tx = 0; counter < 1000; cout << ch, tx++, counter++); };
   std::thread tX = std::thread([&]() {for (tx = 0; counter<1000; cout << '^', tx++, counter++); });
   std::thread tY = std::thread([&]() {for (ty = 0; counter<1000; cout << '_', ty++, counter++); });
   std::thread tZ = std::thread([&]() {for (tz = 0; counter<1000; cout << '-', tz++, counter++); });
   tX.join();
   tY.join();
   tZ.join();
   cout << endl;
   cout << "tX printed " << tx << " characters!" << endl;
   cout << "tY printed " << ty << " characters!" << endl;
   cout << "tZ printed " << tz << " characters!" << endl;
   return 0;
 }
