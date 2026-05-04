#include <iostream>
using namespace std;
class Container {
   static int m_val;
   int m_attr{};
public:
   Container( ) {
      m_val++;
   }
   virtual ~Container( ) {
      m_val--;
   }
   static int howMany( ) {
      return m_val;
   }
};
int Container::m_val = 0;
int main() {
   cout << "Before creating: " << Container::howMany( ) << endl;
   Container* C = new Container[10];
   cout << C[1].howMany( ) << endl;
   delete[] C;
   cout << "After deleting: " << Container::howMany( ) << endl;
   return 0;
}