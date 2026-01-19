#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::path dir = "."; // Current directory

   for (const auto& entry : fs::directory_iterator(dir)) {
      std::cout << entry.path() << "\n";
   }


   for (const auto& entry : fs::recursive_directory_iterator(dir)) {
      std::cout << entry.path() << "\n";
   }
  

   return 0;
}