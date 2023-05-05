#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;
using clk = std::chrono::steady_clock;
void chars(int& n, std::mutex& mx, clk::time_point& sec, char ch) {
   std::scoped_lock<std::mutex> lg(mx);
   for (n = 0; clk::now() < sec; cout << ch, n++);
   sec = clk::now() + chrono::seconds(1);
}
int main() {
   int tx, ty, tz;
   clk::time_point Seconds = clk::now() + chrono::seconds(1);
   mutex key;
   vector<thread> thrds;
   thrds.push_back(thread(chars, ref(tx), ref(key), ref(Seconds), '^'));
   thrds.push_back(thread(chars, ref(ty), ref(key), ref(Seconds), '-'));
   thrds.push_back(thread(chars, ref(tz), ref(key), ref(Seconds), '_'));
   key.lock();
   cout << "GO!" << endl;
   key.unlock();
   for (auto& t : thrds) {
      t.join();
   }
   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "ty Printed " << ty << " characters!" << endl;
   cout << "tz Printed " << tz << " characters!" << endl;
   return 0;
}
