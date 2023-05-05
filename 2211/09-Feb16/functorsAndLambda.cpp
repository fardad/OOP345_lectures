#include <iostream>
#include <fstream >
#include <string>
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
   Line(){ }
   Line(char fill, ostream& ostre = std::cout) : m_fill{ fill }, m_ostr{ ostr } {
   }
   void operator(unsigned len) {
      for (unsigned i = 0; i < len; m_ostr << fill, i++);
      m_ostr << endl;
   }
};


int main() {
   Add addFunctor;
   int x = addFunctor(2, 3);
   Line line, fline('=', ofstream("line.txt"));
   fline(50);
   line(20);
   return 0;
}