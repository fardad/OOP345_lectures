#include <stack>
#include <iostream>
using namespace std;
int main() {
   std::stack<double> prices; // initially empty 

   prices.push(10.43); // add 10.43
   prices.push(20.54); // add 20.54
   prices.push(32.43); // add 32.43
   prices.top() = 5.41;
   while (!prices.empty()) {
      std::cout << prices.top() << "  ";
      prices.pop();
   }
   std::cout << std::endl;
}