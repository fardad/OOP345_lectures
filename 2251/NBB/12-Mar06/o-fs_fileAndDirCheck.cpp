#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::path p = "example.txt";

   if (fs::exists(p)) {
      std::cout << "File exists.\n";
   }
   else {
      std::cout << "File does not exist.\n";
   }

   p = "DEmployee.cpp";

   if (fs::exists(p)) {
      std::cout << "File exists.\n";
   }
   else {
      std::cout << "File does not exist.\n";
   }

   if (fs::is_regular_file(p)) {
      std::cout << "It's a file.\n";
   }
   else if (fs::is_directory(p)) {
      std::cout << "It's a directory.\n";
   }

   p = "12-Mar06";

      if (fs::is_regular_file(p)) {
      std::cout << "It's a file.\n";
   }
   else if (fs::is_directory(p)) {
      std::cout << "It's a directory.\n";
   }

   return 0;
}