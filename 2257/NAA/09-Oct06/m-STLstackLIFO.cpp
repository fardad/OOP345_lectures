#include <iostream>
#include <stack>
using namespace std;

int main() {
   stack<string> actions;
   actions.push("Open");
   actions.push("Edit");
   actions.push("Save");

   while (!actions.empty()) {
      cout << "Undo: " << actions.top() << endl;
      actions.pop();
   }
   return 0;
}