#include <iostream>
using namespace std;
class Container {
   int m_data;
   static  int m_sdata;
public:
   Container( int data ) :m_data{ data } { 
      ++m_sdata;
   };
   ostream& display( ostream& ostr = cout )const {
      return ostr << m_sdata << ": " << m_data;
   }
   static int count( ) {
      return m_sdata;
   }
   virtual ~Container( ) {
      --m_sdata;
   }
};
int Container::m_sdata = 0;


int main( ) {
   cout << "OOP345 NEE May 07" << endl;
   Container* a = new Container( 10 );
   a->display( ) << endl;
   Container* b = new Container( 20 );
   b->display( ) << endl;
   delete a;
   b->display( ) << endl;
   cout << Container::count( ) << endl;
   return 0;
}

