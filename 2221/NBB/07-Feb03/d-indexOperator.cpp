#include <iostream>
#include <string>
using namespace std;

class Name {
public:
   Name(string vfirst, string vlast);
   string first();
   string last();
};
class Directory {
   Name* m_names;
public:
   Directory();
   string operator[](const char* value);
};


int main() {
   Directory D;
   cout << D["Fardad"] << endl;
   cout << D.operator[]("Fardad") << endl;
   // print soleimanloo 
   return 0;
}
