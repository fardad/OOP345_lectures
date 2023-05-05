
#include <vector>
#include <iostream>
using namespace std;
int main() {
   std::vector<double> prices(10000); // initially empty
   if (prices.empty())       // is prices empty?
      std::cout << "prices is empty" << std::endl;
   prices.push_back(10.43); // add 10.43
   prices.push_back(20.54); // add 20.54
   prices.push_back(32.43); // add 32.43
   for (int i = 0; i < prices.size(); i++)
      std::cout << prices[i] << "  ";
   std::cout << std::endl;
   prices.front() = 54.11; // change 1st element 
   prices.pop_back();      // remove last element 
   for (int i = 0; i < prices.size(); i++)
      std::cout << prices[i] << "  ";
   std::cout << std::endl;
   return 0;
}