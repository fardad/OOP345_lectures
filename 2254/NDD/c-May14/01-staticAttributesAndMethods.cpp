#include <iostream>
using namespace std;
class Container {
   int m_value;
   static int m_cnt;
public:
   Container( int value ) :m_value{ value } {
      m_cnt++;
   };
   virtual ~Container( ) {
      m_cnt--;
   }
   static int NoOfObjs( ){
      return m_cnt;
   }
};
int Container::m_cnt = 0;


int main( ) {
   cout << "May14 - OOP345NDD" << endl;
   cout << "No of Countainer Objectes: " << Container::NoOfObjs( ) << endl;
   Container C( 10 );
   cout << "No of Countainer Objectes: " << C.NoOfObjs( ) << endl;

   return 0;
}