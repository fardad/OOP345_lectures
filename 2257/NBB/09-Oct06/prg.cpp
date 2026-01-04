//std::queue – FIFO (First In, First Out)
#include <iostream>
#include <queue>
using namespace std;

int main() {
   queue<int> tickets;
   tickets.push(101);
   tickets.push(102);
   tickets.push(103);

   while (!tickets.empty()) {
      cout << "Serving: " << tickets.front() << endl;
      tickets.pop();
   }
   return 0;
}