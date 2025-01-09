#include <iostream>
using namespace std;

int filescope;

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
int main( ) {
   cout << Container::noOfInstances( ) << endl;
   Container C[100];
   cout << C[30].noOfInstances( ) << endl;
   Container* p = new Container[50];
   cout << Container::noOfInstances( ) << endl;
   delete[] p;
   cout << Container::noOfInstances( ) << endl;
   return 0;
}