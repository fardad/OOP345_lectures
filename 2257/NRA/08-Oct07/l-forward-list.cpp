#include <iostream>
#include <forward_list>
using namespace std;

int main() {
   forward_list<string> names = { "Alice", "Bob", "Charlie" };
   names.push_front("Zara");

   auto it = names.insert_after(names.begin(), "David");
   names.erase_after(it);

   for (const auto& name : names)
      cout << name << " ";
   cout << endl;

   return 0;
}