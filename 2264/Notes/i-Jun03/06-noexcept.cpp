#include <iostream>
using namespace std;

void d() { throw "d() throws\n"; }
void e() {
   try {
      d();
   }
   catch (const char* msg) {
      cout << msg;
   }
}
void f() { throw "f() throws\n"; }
void g() noexcept { e(); }  // safe
void h() noexcept { f(); }  // unsafe it will terminate the application completely

int main() {
   cout << "Calling g: ";
   g();
   cout << "Calling h: ";
   h(); // terminates
   cout << "Normal exit\n";
   return 0;
}