#include <iostream>
#include <thread>
using namespace std;
void carets() {
   for (int i = 0; i < 40; i++, cout << '^');
}
void dashes() {
   for (int i = 0; i < 40; i++, cout << '-');
}
void pluses() {
   for (int i = 0; i < 40; i++, cout << '+');
}
int main() {
   thread tc(carets);
   thread td(dashes);
   thread tp(pluses);
   tc.join();
   td.join();
   tp.join();
   return 0;
}