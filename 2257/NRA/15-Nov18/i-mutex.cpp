#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
using clk = chrono::steady_clock;

int main() {
   int tx{}, ty{};
   auto Seconds = clk::now() + chrono::seconds(1);
   mutex theLock;

   theLock.lock();  // lock before starting threads

   thread tX([&]() {
      theLock.lock();  // wait for GO and for tY
      for (tx = 0; clk::now() < Seconds; ++tx) {
         cout << '^';
      }
      Seconds = clk::now() + chrono::seconds(1); // reset for tY
      theLock.unlock();
      });

   thread tY([&]() {
      theLock.lock();  // wait for GO and for tX
      for (ty = 0; clk::now() < Seconds; ++ty) {
         cout << '_';
      }
      Seconds = clk::now() + chrono::seconds(1); // not really needed
      theLock.unlock();
      });

   cout << "GO!" << endl;
   theLock.unlock();  // let exactly one of them in

   tX.join();
   tY.join();

   cout << endl;
   cout << "tX Printed " << tx << " characters!" << endl;
   cout << "ty Printed " << ty << " characters!" << endl;

   return 0;
}
