#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
   fs::copy("source.txt", "destination.txt", fs::copy_options::overwrite_existing);
   // rename and move
   fs::rename("old_name.txt", "new_name.txt");
   return 0;
}