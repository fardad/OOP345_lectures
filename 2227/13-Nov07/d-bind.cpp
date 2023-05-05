#include <iostream>
#include <functional>
#include <vector>
using namespace std;

ostream& line(char ch, int len) {
   for(; len > 0; len--, cout << ch);
   return cout;
}

int main() {
   auto dash40 = bind(line, '-', 40);

   dash40() << endl;
   return 0;
}
