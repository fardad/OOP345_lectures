#include <iostream>
#include <fstream>

int main() {
   std::ofstream fout("log.txt", std::ios::app);  // Append mode
   if (!fout) {
      std::cout << "Open failed!" << std::endl;
      return 1;
   }

   fout << "Entry: " << 2025 << std::endl;
   fout.close();

   // Quick verify
   std::cout << "Logged entry for year 2025." << std::endl;
   return 0;
}