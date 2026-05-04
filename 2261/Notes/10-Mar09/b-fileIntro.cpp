// intro_file.cpp - Basic file stream demo
#include <iostream>
#include <fstream>
#include <string>

int main() {
   // Write to file
   std::ofstream writer("grades.txt");
   writer << "Math: 95\nEnglish: 88\n";
   writer.close();  // Flushes buffer

   // Read from file
   std::ifstream reader("grades.txt");
   std::string subject;
   int score;
   while (reader >> subject >> score) {
      std::cout << "Subject: " << subject << ", Score: " << score << std::endl;
   }
   reader.close();
   return 0;
}
