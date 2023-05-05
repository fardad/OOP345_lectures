#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;
using clk = std::chrono::steady_clock;
class Chars {
   char m_ch;
   int m_noc=0;
public:
   Chars(char ch) :m_ch(ch) {  }
   void operator()(clk::time_point sec) {
      for (; clk::now() < sec; cout << m_ch, m_noc++);
   }
   int noc() {
      return m_noc;
   }
};
int main() {
   Chars tx('^'), ty('-'), tz('_');
   clk::time_point Seconds = clk::now() + chrono::seconds(3);
   vector<thread> thrds;
   thrds.push_back(thread(ref(tx), Seconds));
   thrds.push_back(thread(ref(ty), Seconds));
   thrds.push_back(thread(ref(tz), Seconds));
   for (auto& t : thrds) {
      t.join();
   }
   cout << endl;
   cout << "tX Printed " << tx.noc() << " characters!" << endl;
   cout << "ty Printed " << ty.noc() << " characters!" << endl;
   cout << "ty Printed " << tz.noc() << " characters!" << endl;
   return 0;
}
