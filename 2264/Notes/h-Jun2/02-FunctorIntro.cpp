#include <iostream>
using namespace std;
class Add {// function object : Functor
   size_t m_noOfCalls{};
public:
   int operator()(int num1, int num2) {
      m_noOfCalls++;
      return num1 + num2;
   }
   size_t noOfCalls()const {
      return m_noOfCalls;
   }
};
int main() {
   cout << "OOP345 NAA - Jun 02" << endl;
   Add add;
   cout << add(10, 20) << endl;
   cout << add(20, 30) << endl;
   cout << add.noOfCalls() << endl;

   return 0;
}