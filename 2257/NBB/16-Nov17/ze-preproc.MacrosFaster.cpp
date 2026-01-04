// efficiency.cpp
#include <iostream>
#include <chrono>

#define ADD_MACRO(A, B) ((A) + (B))

int addFunction(int a, int b) { return a + b; }

int main() {
   const int iterations = 100000000;  // 1e8 for measurable time

   // Time macro
   auto startMacro = std::chrono::high_resolution_clock::now();
   long long sumMacro = 0;
   for (int i = 0; i < iterations; ++i) {
      sumMacro += ADD_MACRO(i, i + 1);
   }
   auto endMacro = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> durationMacro = endMacro - startMacro;

   // Time function
   auto startFunc = std::chrono::high_resolution_clock::now();
   long long sumFunc = 0;
   for (int i = 0; i < iterations; ++i) {
      sumFunc += addFunction(i, i + 1);
   }
   auto endFunc = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> durationFunc = endFunc - startFunc;

   std::cout << "Macro time: " << durationMacro.count() << " seconds" << std::endl;
   std::cout << "Function time: " << durationFunc.count() << " seconds" << std::endl;
   std::cout << "(Note: Macro is typically faster due to no function call overhead)" << std::endl;

   return 0;
}