#include <iostream>
#include <string>
using namespace std;
class Owner;
class Name {
   int size;
   string value;
   Owner* owner{};// 1
public:
   Name(string val) : value{ val }{// 2
      size = 0;  // 3 NOT intialziation
   }
};

int main() {
   Name N("fardad");
   return 0;
}