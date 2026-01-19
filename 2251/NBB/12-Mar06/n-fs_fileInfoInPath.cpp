#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::path p = "/home/user/example.txt";

   std::cout << "Filename: " << p.filename() << "\n";
   std::cout << "Extension: " << p.extension() << "\n";
   std::cout << "Parent path: " << p.parent_path() << "\n";
   return 0;
}