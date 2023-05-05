#include <iostream>
#include <string>
using namespace std;
// 1 change all the types of interest to the template type
// 2 add the tag of template <type> to all the class name
   // except, the name of the class right after the template
   // all names of constructor definitions
   // the name of destructor
// do the same to all othe scopes envloved in the tempalge code
template<typename type>
class Container {
   string title;
   type value;
public:
   Container(string str) :title(str), value{}{
     
   }
   Container(string str, type v) :title(str), value{ v }{
   }
   void set(type val);
   type get()const;

   Container<type>& operator=(type val);

   Container<type>& operator=(Container<type>& C);

   ostream& display(ostream& os = cout)const;
   virtual ~Container();
};

template<typename type>
Container<type>::~Container() {
}

template <typename type>
ostream& operator<<(ostream& os, const Container<type>& C) {
   return C.display(os);
}


template <typename type>
Container<type>& Container<type>::operator=(type val) {
   set(val);
   return *this;
}

template <typename type>
Container<type>& Container<type>::operator=(Container<type>& C) {
   set(C.val);
   return *this;
}

template <typename type>
void Container<type>::set(type val) {
   value = val;
}

template <typename type>
type Container<type>::get()const {
   return value;
}

template <typename type>
ostream& Container<type>::display(ostream& os)const {
   return os << title << ": " << value;
}

int main() {
   Container<int> C("water");
   Container<double> Cf("Oil");
   Cf = 23.456;
   C.set(55);
   cout << C << endl;
   cout << Cf << endl;
  
   return 0;
}