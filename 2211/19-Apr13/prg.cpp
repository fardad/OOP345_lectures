#include <iostream>
#include "Stack.h"
using namespace std;
using namespace sdds;
int main() {
   Stack<int> S;
   for (int i = 10; i < 50; i += 10) {
      S.push(i);
      cout << "Pushing " << i << endl;
   }
   Stack<int> T = S;
   while (!S.isEmpty()) {
      cout << S.pop() << " ";
   }
   cout << endl;
   S = move(T);
   while (!S.isEmpty()) {
      cout << S.pop() << " ";
   }
   cout << endl;
   while (!T.isEmpty()) {
      cout << T.pop() << " ";
   }
   cout << endl;

   return 0;
}