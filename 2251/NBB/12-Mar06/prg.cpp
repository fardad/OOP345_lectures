#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::perms p = fs::status("d_employee.bin").permissions();

   if ((p & fs::perms::owner_write) != fs::perms::none) {
      std::cout << "Writable by owner.\n";
   }

   return 0;
}