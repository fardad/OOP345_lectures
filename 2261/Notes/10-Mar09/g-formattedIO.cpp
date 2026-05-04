// read_write_formatted.cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
   // Write formatted
   std::ofstream out("info.txt");
   out << "ID:123\nAge:25\n";
   out.close();

   // Read formatted
   std::ifstream in("info.txt");
   std::string key;
   int value;
   while (in >> key >> value) {
      std::cout << key << " = " << value << std::endl;
   }
   in.close();
   return 0;
}