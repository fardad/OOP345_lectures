// list_demo.cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
   list<int> numbers = { 10, 20, 30 };
   numbers.push_front(5);
   numbers.push_back(40);

   auto it = numbers.begin();
   advance(it, 2);
   numbers.insert(it, 25);

   cout << "List: ";
   for (int n : numbers) cout << n << " ";
   cout << endl;

   numbers.remove(25);
   cout << "After removal: ";
   for (int n : numbers) cout << n << " ";
   cout << endl;
   return 0;
}