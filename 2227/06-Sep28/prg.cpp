#include <iostream>
using namespace std;

class Container{
   int m_data;
public:
   Container(int d=0) {
      cout << "Constr" << d << endl;
      m_data = d;
   }
   Container& operator=(int d){
      m_data = d;
      return *this;
   }
   int& value() {
      return m_data;
   }
   void  display() {
      cout << m_data << endl;
   }
   ~Container() {
      cout << "Destr " << m_data << endl;
   }
};

int main() {
   Container C;
   int i;

   i = 10;
   C.value() = 23;
   C.display();
   i = C.value();
   Container(10).value() = 25;
   cout << "Done" << endl;

   (Container(100) = 35).display();

   C = Container(34);
   C.display();
   return 0;
}