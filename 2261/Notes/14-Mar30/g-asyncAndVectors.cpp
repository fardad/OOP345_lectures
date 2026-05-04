#include <iostream>
#include <chrono>
#include <vector>
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
   auto Seconds = clk::now() + chrono::seconds(3);

   Chars tx('^'), ty('-'), tz('_');

   vector<future<int>> f;
   f.reserve(3); // optional, but nice

   f.emplace_back(async(launch::async, tx, Seconds));
   f.emplace_back(async(launch::async, ty, Seconds));
   f.emplace_back(async(launch::async, tz, Seconds));

   int x[3]{};
   for (int i = 0; i < 3; i++) {
      x[i] = f[i].get();
   }

   cout << '\n';
   cout << "tX Printed " << x[0] << " characters!" << endl;
   cout << "tY Printed " << x[1] << " characters!" << endl;
   cout << "tZ Printed " << x[2] << " characters!" << endl;

   return 0;
}
