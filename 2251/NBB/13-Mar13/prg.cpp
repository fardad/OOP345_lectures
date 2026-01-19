#include <iostream>
using namespace std;
template <typename T>
class uPtr {
   T* m_ptr{ };
public:
   uPtr( T* ptr = nullptr ) :m_ptr( ptr ) { }
   T& operator*( ) {
      return *m_ptr;
   }



   virtual ~uPtr( ) {
      delete m_ptr;
   }
};



int main( ) {
   uPtr<int> ptr(new int);
   cout << "Please enter an int:\n> ";
   cin >> *ptr;
   cout << "The number you enterd is " << *ptr << endl;
   return 0;
}
