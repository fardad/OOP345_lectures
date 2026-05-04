#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::path p = "example.txt";

   fs::create_directory("new_folder");

   fs::create_directories("parent/child/grandchild");


   //fs::remove("example.txt"); // Deletes file or empty directory
   //fs::remove_all("parent");  // Recursively deletes directory and contents

   return 0;
}