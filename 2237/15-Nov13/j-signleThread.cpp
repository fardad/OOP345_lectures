#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
long long sum(const vector<int>& data) {
   long long total = 0;
   for (int value : data) {
      total += value;
   }
   return total;
}

int main() {
   vector<int> data(1000000000, 1); // Large vector of 1s

   auto start = chrono::high_resolution_clock::now();
   long long total = sum(data);
   auto end = chrono::high_resolution_clock::now();

   chrono::duration<double> diff = end - start;
   cout << "Single-threaded sum: " << total << "\n";
   cout << "Time taken: " << diff.count() << " seconds\n";

   return 0;
}
