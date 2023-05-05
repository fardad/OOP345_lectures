#include <iostream>
using namespace std;
class Tag {
   int num { 1 }; // 1 
   //int num = 1;
   string value;
   bool vip;
public:
   Tag(string val) : value{ val }, vip{ false } {// 2
  //    vip = false;  // 3 NOT intialziation
   }
};
int main() {
   int a = 20;
   int b;
   b = 20;
   Tag N("Fred Soley");
   return 0;
}



