#include <iostream>
#include <string>
using namespace std;

class Name {
public:
   Name(string vfirst="", string vlast="");
   string first();
   string last();
   Name& operator++(int);
};
class Directory {
   Name* m_names;
public:
   Directory();
   string operator[](const char* value);
};


int main() {
   int i = 1;
   Name N;
   Directory D;
   cout << D["Fardad"] << endl;
   cout << D.operator[]("Fardad") << endl;
   (N++)++;  // no problem lvalue
   (i++)++;  //error prvalue;
   // print soleimanloo 
   return 0;
}
