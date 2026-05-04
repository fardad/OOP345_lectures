#include <iostream>
#include <vector>
using namespace std;

template <typename type>
class Wrapper {
   type* m_data;
public:
   Wrapper( type& data ) :m_data( &data ) { }
   operator type& () {
      return *m_data;
   }
};



int main( ) {
   int a = 10, b = 20, c = 30;
   vector<int> v{ a, b, c };
   vector<Wrapper<int>> w{ a, b, c };
   for ( auto& i : v ) {
      cout << i << " ";
      i += 20;
   }
   cout << endl;
   cout << "Vector:\n";
   for ( auto& i : v ) {
      cout << i << " ";
   }
   cout << endl;
   cout << "a, b and c" << endl;
   cout << a << " " << b << " " << c << endl;
   cout << "The Wrapper:\n";
   for ( auto& i : w ) {
      cout << i << " ";
      i += 20;
   }
   cout << endl;
   cout << "Vector:\n";
   for ( auto& i : w ) {
      cout << i << " ";
   }
   cout << endl;
   cout << "a, b and c" << endl;
   cout << a << " " << b << " " << c << endl;

   return 0;
}