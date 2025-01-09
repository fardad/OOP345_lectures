#include <iostream>
using namespace std;
class Container {
   int m_data;
   static int m_cnt;
public:
   Container( int data = 1 ) {
      m_data = data;
      m_cnt++;
   }
   ostream& display( ostream& ostr = cout ) {
      ostr << m_data << " (" << noOfInstances( ) << ")" << endl;
      return ostr;
   }
   static int noOfInstances( ) {  // class function class method
      //cout << m_data << endl; can only access the static members
      return m_cnt;
   }
   ~Container( ) {
      m_cnt--;
   }
};
int Container::m_cnt = 0;
int main() {
   Container C[3] = { 10, 20, 30 };
   C[0].display();
   Container* p;
   p = new Container(40);
   p->display();
   delete p;
   C[1].display();
   cout << Container::noOfInstances() << endl;
   return 0;
}