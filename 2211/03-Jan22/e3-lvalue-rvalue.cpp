#include <iostream>
using namespace std;
class Name {
private:
   char* m_value;//  = nullptr; // could have had it here
public:
   Name(const char* value = nullptr) :m_value(nullptr) {
      if (value) {
         int size = 0;
         while (value[size++]);// size = strlen + 1
         m_value = new char[size--];  // allocate size then size-=1
                                      // strcopy backwards, firs null termination copied, if not at the first, go back once and opy the value, repeat
         for (m_value[size] = value[size]; size; m_value[size] = value[--size]);
      }
   }
   ostream& print(ostream& os)const {
      if (m_value) os << m_value;
      return os;
   }
   ~Name() {
      delete[] m_value;
   }
};

ostream& operator<< (ostream& os, const Name& N) {
   os << "lvalue: ";
   return N.print(os);
}
ostream& operator<< (ostream& os, Name&& N) {
   os << "rvalue: ";
   return N.print(os);
}


int main() {
   Name A = "Fred";
   cout << A << endl;
   cout << Name("Joe") << endl;
   return 0;
}
