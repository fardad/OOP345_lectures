#include <iostream>
using namespace std;
class Num {
   int m_value;
   static int m_s;
public:
   Num(int value = 0) :m_value{ value } {
      m_s++;
   }
   static void NoOfObjects() {
      //cout << m_value << endl; // can not be done 
      cout << "Total number of " << m_s << " nums exist" << endl;
   }
   void prn()const {
      cout << "m_value is: " << m_value << endl;
      cout << "in one of " << m_s << " objects" << endl;
   }
   virtual ~Num() {
      m_s--;
   }
};
int Num::m_s = 0; // initializing

int main() {
   Num::NoOfObjects();
   Num N{ 10 }, M{ 50 };
   Num::NoOfObjects();
   Num* p = new Num[100];
   Num::NoOfObjects();
   delete[] p;
   Num::NoOfObjects();
   return 0;
}


