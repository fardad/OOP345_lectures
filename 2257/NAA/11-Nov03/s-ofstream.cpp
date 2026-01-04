// reverse_rotate.cpp
#include <iostream>
#include <vector>
#include <fstream>

int main() {
   std::ofstream fout("output.txt");
   std::vector<int> v = { 1, 2, 3, 4, 5 };
   std::reverse(v.begin(), v.end());
   fout << "Reversed: ";
   for (int n : v) fout << n << " ";  // 5 4 3 2 1
   fout << std::endl;

   std::rotate(v.begin(), v.begin() + 2, v.end());  // Rotate left by 2
   fout << "Rotated: ";
   for (int n : v) fout << n << " ";  // 3 2 1 5 4
   fout << std::endl;
   return 0;
}