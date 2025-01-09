#include <iostream>
using namespace std;
class Container {
   int m_value;
public:
   Container(int value=0) :m_value{ value } {
      clog << "Creating Container with " << value << endl;
   }
   Container& operator=(int value) {
      clog << "setting container with " << m_value << " to " << value << endl;
      m_value = value;
      return *this;
   }
   // A = B + C;
   // Query, means no side effect
   Container operator+(const Container& roperand)const {
      return Container(m_value + roperand.m_value);
   }
   ostream& display(ostream& ostr = cout)const {
      return ostr << m_value;
   }
   virtual ~Container() {
      clog << "Removing Container with " << m_value << endl;
   }
};
ostream& operator<<(ostream& ostr, const Container& C) {
   return C.display(ostr);
}

int main() {
   //clog.setstate(ios::failbit);
   Container A;
   const Container D = 10;
   Container C = 30;
   cout << C << endl;
   C = int(50.23);
   cout << C << endl;
   cout << (Container(200) = 100) << endl;
   cout << C << endl;
   A = D + C;
   cout << "after the operator + call " << endl;
   cout << A << endl;
   A = D + Container(500);
   cout << "after the explicit xvalue creation" << endl;
   A = D + 1000;
   cout << "after automatic casting" << endl;
   return 0;
}