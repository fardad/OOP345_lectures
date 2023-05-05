#ifndef  SDDS_CONAINTER_H
#define  SDDS_CONAINTER_H
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
   template<typename type>
   class Container {
      string title;
      type value;
   public:
      Container(string str = "X") :title(str), value{}{

      }
      Container(string str, type v) :title(str), value{ v }{
      }
      void set(type val);
      type get()const;

      Container<type>& operator=(type val);

      Container<type>& operator=(const Container<type>& C);

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
   Container<type>& Container<type>::operator=(const Container<type>& C) {
      set(C.value);
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
}
#endif // ! SDDS_CONAINTER_H
