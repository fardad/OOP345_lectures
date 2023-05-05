#include <iostream>
#include <thread>
using namespace std;
void prn(char ch) {
   for (int i = 0; i < 40; i++, cout << ch);
}
int main() {
   thread tc(prn,'^');
   thread td(prn,'-');
   thread tp(prn,'+');
   tc.join();
   td.join();
   tp.join();
   cout << "here" << endl;
   return 0;
}