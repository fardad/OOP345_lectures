#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ofstream file("nums.txt");
   vector<double> d = { 10.1, 11.2, 12.3, 13.4, 14.5 };
   for (auto& v : d) {
      file << v << ' ';
   }
   return 0;
}