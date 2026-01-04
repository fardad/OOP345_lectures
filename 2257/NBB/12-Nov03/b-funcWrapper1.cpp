#include <functional>  
#include <string>
#include <iostream>
using namespace std;

void prn(std::string str) {
   std::cout << str;
}
int main() {
   //  std::function<retType(arg1type, arg2tpe, etc.)> fw;
   std::function<void(std::string)> fw = prn;
   fw("Hello!");
   return 0;
}