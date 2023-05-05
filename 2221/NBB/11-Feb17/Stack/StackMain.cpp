#include <iostream>
#include <stack>
using namespace std;

int main() {
   std::stack<double> d;
   d.push(2.34);
   d.push(3.34);
   d.push(4.34);
   d.push(5.34);
   while (!d.empty()) {
      cout << d.top() << endl;
      d.pop();
   }
   cout << endl;
   return 0;
}