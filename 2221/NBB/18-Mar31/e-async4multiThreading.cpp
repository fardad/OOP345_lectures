#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

using namespace std;
typedef unsigned long long ull;
ull sum(ull beg, ull end) {
   ull s = 0, i;
   for (i = beg; i <= end; s += i, i++);
   return s;
}


using clk = std::chrono::steady_clock;
int main() {
   clk::time_point start = clk::now();
   ull beg = 0, end = 1231231231;
   ull step = end / 4;
   vector<future<ull>> f(4);
   for (auto& s : f) {
      s = async(sum, beg, end < beg + step ? end : beg + step);
      beg = beg + step + 1;
   }
   ull sum = 0;
   for (auto& s : f) {
      sum += s.get();
   }
   cout <<"sum:" << sum << endl;
   clk::time_point stop = clk::now();
   cout << "time: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << endl;
   return 0;
}