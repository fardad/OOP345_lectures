#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ofstream file("nums.txt");
   vector<double> d{ 10.123456, 11.2343545, 12.334453 , 13.43434 };
   for (auto& v : d) {
      file << v << " ";
   }
   return 0;
}