#include <iostream>
#include <thread>
using namespace std;
void prn(int& len, string str) {
   for (int i = 0; i < 40; i++, cout << str);
   len = 40 * str.length();
}
int main() {
   int c{}, d{}, p{};
   cout << "===================================================================" << endl;
   thread tc(prn,ref(c),"^^");
   thread td(prn,ref(d),"-");
   thread tp(prn,ref(p), "+++");
   tc.join();
   td.join();
   tp.join();
   cout << endl << "===================================================================" << endl;
   cout << "tc printed:  " << c << endl;
   cout << "td printed:  " << d << endl;
   cout << "tp printed:  " << p << endl;
   return 0;
}