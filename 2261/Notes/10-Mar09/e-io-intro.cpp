// fstream_demo.cpp
#include <iostream>
#include <fstream>

int main() {
   std::fstream f("counter.txt", std::ios::in | std::ios::out | std::ios::trunc);
   if (!f) {
      std::cout << "Failed to open!" << std::endl;
      return 1;
   }

   f << "Count: 5\n";  // Initial write
   f.seekg(0);  // Reset to start to get(read)
   int count;
   f >> count;  // Read
   std::cout << "Initial count: " << count << std::endl;

   f.seekp(7);  // Position after "Count: " to put(write)
   f << (count + 1);  // Update
   f.close();
   return 0;
}