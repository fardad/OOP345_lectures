#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::path p = "example.txt";
   fs::path p1 = "/home/user/documents";
   fs::path p2 = "file.txt";
   std::cout << "Path: " << p << "\n";
   fs::path fullPath = p1 / p2;  // Combines paths
   std::cout << "Full path: " << fullPath << "\n";
   return 0;
}