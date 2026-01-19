#include <istream>
using namespace std;

class Person {

public:
   // always have a destructor and make it virtual
   // you can change it later if you need
   virtual ~Person( ) = default;
};