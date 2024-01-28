#include <iostream>
#include "DynArray.h"
using namespace std;
using namespace sdds;
struct Container {
   int m_data;
   Container(int value = 10) {
      m_data = value;
   }
   Container& operator=(int value) {
      m_data = value;
      return *this;
   }
};
ostream& operator<<(ostream& ostr, const Container C) {
   return ostr << C.m_data;
}

int main() {
   DynArray<Container> C(4);
   int i;
   for(i = 0; i < C.size(); i++) {
      C[i] = i + 10;
   }
   cout << C << endl;
   return 0;
}