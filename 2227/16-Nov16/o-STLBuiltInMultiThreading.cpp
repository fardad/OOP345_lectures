// Algorithms - Execution Policies - C++17
// policies.cpp

#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>
#include "execution" // for Intel 19.1
#include "numeric"   // for Intel 19.1

using namespace std::chrono;

// reportTime inserts duration (span) into std::cout
//
void reportTime(const char* msg, steady_clock::duration span)
{
   auto ms = duration_cast<milliseconds>(span);
   std::cout << msg << ": " << ms.count() << " millisecs" << std::endl;
}

int main()
{
   std::vector<double> x(1 << 27, 0.5);

   steady_clock::time_point ts, te;

   ts = steady_clock::now();
   double par = std::reduce(std::execution::par, x.begin(), x.end());
   te = steady_clock::now();
   std::cout << "sum = " << par << std::endl;
   reportTime("par", te - ts);

   ts = steady_clock::now();
   double seq = std::reduce(std::execution::seq, x.begin(), x.end());
   te = steady_clock::now();
   std::cout << "sum = " << seq << std::endl;
   reportTime("seq", te - ts);

   ts = steady_clock::now();
   double ss = std::accumulate(x.begin(), x.end(), 0.0);
   te = steady_clock::now();
   std::cout << "sum = " << ss << std::endl;
   reportTime("serial", te - ts);
}