// note this is C++ 20 and after

#include <iostream>
#include <chrono>
#include <thread>      // std::jthread is here
#include <vector>

using namespace std;
using clk = chrono::steady_clock;

void chars(int& n, clk::time_point sec, char ch) {
   for (n = 0; clk::now() < sec; ++n) {
      cout << ch;
   }
}

int main() {
   int tx{}, ty{}, tz{};

   clk::time_point Seconds = clk::now() + chrono::seconds(3);

   // Using jthread → no manual join() needed!
   vector<jthread> thrds;
   thrds.emplace_back(chars, ref(tx), Seconds, '^');
   thrds.emplace_back(chars, ref(ty), Seconds, 'x');
   thrds.emplace_back(chars, ref(tz), Seconds, '_');

   // No for-loop with join() anymore — destructors call join() automatically
   // (if the thread is joinable)

   cout << endl;
   cout << "tX Printed " << tx << " characters!\n";
   cout << "tY Printed " << ty << " characters!\n";
   cout << "tZ Printed " << tz << " characters!\n";

   return 0;
}