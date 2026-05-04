// open_close.cpp
#include <iostream>
#include <fstream>

int main() {
   std::ofstream fout;  // Default
   fout.open("temp.bin", std::ios::out | std::ios::binary | std::ios::trunc);
   if (fout.is_open()) {
      const char data[] = "Raw bytes";
      fout.write(data, 9);  // Write first 9 bytes
      fout.close();  // Flush
      std::cout << "Binary file created and closed." << std::endl;
   }
   else {
      std::cout << "Open error!" << std::endl;
   }
   return 0;
}