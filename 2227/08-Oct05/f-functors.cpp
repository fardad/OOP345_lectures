#include <iostream>
using namespace std;

class Line {
   char m_fill{ '-' };
public:
   Line(char fill = '-') :m_fill{ fill } {};
   ostream& operator()(size_t len) {
      for (size_t i = 0; i < len; i++) cout << m_fill;
      return cout;
   }
};



int main() {
   Line dash, star('*');
   dash(10) << endl;
   star(20) << endl;
   return 0;
}