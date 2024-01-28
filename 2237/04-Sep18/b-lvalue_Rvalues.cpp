#include <iostream>
using namespace std;
class Name {
private:
   char* m_value{};//  = nullptr; // could have had it here
public:
   Name(const char* value = nullptr)  {
      if(value) {
         int size = 0;
         //strlen
         while(value[size++]);// size = strlen + 1
         m_value = new char[size--];  // allocate size then size-=1
         // strcopy backwards, first null termination copied, if not at the first, go back once and opy the value, repeat
         //strcpy
         for(m_value[size] = value[size]; size; m_value[size] = value[--size]);
      }
   }
   Name(const Name& N) {
      if(N.m_value) {
         int size = 0;
         //strlen
         while(N.m_value[size++]);// size = strlen + 1
         m_value = new char[size--];  // allocate size then size-=1
         // strcopy backwards, first null termination copied, if not at the first, go back once and opy the value, repeat
         //strcpy
         for(m_value[size] = N.m_value[size]; size; m_value[size] = N.m_value[--size]);
      }
   }
   ostream& print(ostream& os)const {
      if(m_value) os << m_value;
      return os;
   }
   ~Name() {
      cout << "destructor" << endl;
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

void prnName(Name N) {
   cout << N << endl;
}

int main() {
   Name A = "Jack"; 
   Name  B = A;
   Name C = Name("John");
   cout << "After Name Creations!" << endl;

   cout << A << endl;
   cout << B << endl;
   A = B;
   B = A;
   cout << Name("Iman") << endl;
   prnName(Name("Wilson")); // prnName(Name N = Name("Wilson"));


   return 0;


}