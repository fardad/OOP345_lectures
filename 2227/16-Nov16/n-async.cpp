#include <thread>
#include <iostream>
#include <future>
using namespace std;
typedef unsigned long long ull;
using clk = std::chrono::steady_clock;
class Chars {
   char m_ch;
public:
   Chars(char ch) :m_ch(ch) {}
   int operator()(clk::time_point sec) {
      int noc = 0;
      for (; clk::now() < sec; cout << m_ch, noc++);
      return noc;
   }
};

int main() {
   auto Seconds = clk::now() + chrono::seconds(15);
   Chars tx('^'), ty('-'), tz('+');
   future<int> f1 = async(tx, Seconds);
   future<int> f2 = async(ty, Seconds);
   future<int> f3 = async(tz, Seconds);
   int x = f1.get();
   int y = f2.get();
   int z = f3.get();
   cout << endl;
   cout << "tX Printed " << x << " characters!" << endl;
   cout << "ty Printed " << y << " characters!" << endl;
   cout << "tz Printed " << z << " characters!" << endl;
   return 0;
}

