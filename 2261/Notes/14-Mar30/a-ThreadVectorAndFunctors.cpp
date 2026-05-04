#include <thread>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using clk = chrono::steady_clock;

class Chars {
   char m_ch;
   int m_noc = 0;
public:
   Chars(char ch) : m_ch(ch) {}
   void operator()(clk::time_point sec) {
      for (; clk::now() < sec; ++m_noc) {
         cout << m_ch;
      }
   }
   int noc() const {
      return m_noc;
   }
};

int main() {
   Chars tx('^'), ty('-'), tz('_');
   clk::time_point Seconds = clk::now() + chrono::seconds(1);

   vector<thread> thrds;
   thrds.emplace_back(ref(tx), Seconds);
   thrds.emplace_back(ref(ty), Seconds);
   thrds.emplace_back(ref(tz), Seconds);

   for (auto& t : thrds) {
      t.join();
   }

   cout << endl;
   cout << "tX Printed " << tx.noc() << " characters!" << endl;
   cout << "tY Printed " << ty.noc() << " characters!" << endl;
   cout << "tZ Printed " << tz.noc() << " characters!" << endl;

   return 0;
}
