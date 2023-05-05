#include <iostream>
#include <fstream>
using namespace std;

class Add {
public:
   int operator()(int a, int b) {
      return a + b;
   }
};

class Line {
   char m_fill{ '*' };
   ostream& m_ostr{ std::cout };
public:
   Line() {
   }
   Line(char fill, ostream& ostr = std::cout) : m_fill{ fill }, m_ostr{ ostr } {
   }
   void operator()(unsigned len) {
      for (unsigned i = 0; i < len; m_ostr << m_fill, i++);
      m_ostr << endl;
   }
};


int main() {
   ofstream f("line.txt");
   Line divider('-'), fileDivider('=',f);
   Add addFunctor, heehaw;
   int x = addFunctor(2, 3);
   divider(50);
   cout << x << endl;
   x = heehaw(5, 6);
   fileDivider(70);
   cout << x << endl;
}