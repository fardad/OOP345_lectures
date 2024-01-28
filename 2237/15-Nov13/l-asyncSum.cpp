#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include <numeric>

long long partial_sum(const std::vector<int>& data, size_t start, size_t end) {
   long long sum{};
   for (size_t i = start; i < end; i++) {
      sum += data[i];
   }
   return sum;
}

int main() {
   std::vector<int> data(100000000, 1); // Large vector of 1s
   size_t num_threads = std::thread::hardware_concurrency();
   std::vector<std::future<long long>> futures;

   auto start = std::chrono::high_resolution_clock::now();
   size_t chunk_size = data.size() / num_threads;

   for (size_t i = 0; i < num_threads; i++) {
      size_t start_index = i * chunk_size;
      size_t end_index = (i + 1) * chunk_size;
      futures.push_back(std::async(std::launch::async, partial_sum, std::ref(data), start_index, end_index));
   }

   long long total = 0;
   for (auto& future : futures) {
      total += future.get();
   }

   auto end = std::chrono::high_resolution_clock::now();

   std::chrono::duration<double> diff = end - start;
   std::cout << "Async sum: " << total << "\n";
   std::cout << "Time taken: " << diff.count() << " seconds\n";

   return 0;
}
