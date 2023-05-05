#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
   ifstream file("nums.txt");
   double d;
   while (file >> d) {
      cout << d << endl;
   }
   return 0;
}