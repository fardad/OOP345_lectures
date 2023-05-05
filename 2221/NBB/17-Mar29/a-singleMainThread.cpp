#include <iostream>
using namespace std;
void carets() {
   for (int i = 0; i < 40; i++, cout << '^'); cout << endl;
}
void dashes() {
   for (int i = 0; i < 40; i++, cout << '-'); cout << endl;
}

int main() {
   carets();
   dashes();
   return 0;
}