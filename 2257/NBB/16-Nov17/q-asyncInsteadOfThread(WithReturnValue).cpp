#include <iostream>
#include <chrono>
#include <future>

using namespace std;
using clk = chrono::steady_clock;

class Chars {
   char m_ch{};
public:
   Chars(char ch) : m_ch(ch) {}
   int operator()(clk::time_point sec) {
      int noc = 0;
      for (; clk::now() < sec; ++noc) {
         cout << m_ch;
      }
      return noc;
   }
};

int main() {
   auto Seconds = clk::now() + chrono::seconds(2);
   Chars tx('^'), ty('-'), tz('_');

   future<int> f1 = async(launch::async, tx, Seconds);
   future<int> f2 = async(launch::async, ty, Seconds);
   future<int> f3 = async(launch::async, tz, Seconds);

   int x = f1.get();
   int y = f2.get();
   int z = f3.get();

   cout << '\n';
   cout << "tX Printed " << x << " characters!" << endl;
   cout << "tY Printed " << y << " characters!" << endl;
   cout << "tZ Printed " << z << " characters!" << endl;

   return 0;
}


/*
launch::async
Thread starts immediately.
Task runs in parallel with caller.

launch::deferred
Task waits.
Does nothing until .get().
Runs synchronously in caller thread.
No real concurrency.

Default (async | deferred)
Compiler decides.
May run in a new thread.
OR may defer.
You cannot rely on it.

*/