#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::path p = "d_employee.bin";

   if (fs::exists(p) && fs::is_regular_file(p)) {
      std::cout << "Size: " << fs::file_size(p) << " bytes\n";
   }

   return 0;
}