#include <iostream>
#include <string>
using namespace std;

class Add {
   size_t m_noOfCalls{};
public:
   int operator()(int num1, int num2) {
      m_noOfCalls++;
      return num1 + num2;
   }
   int noOfCalls()const {
      return m_noOfCalls;
   }

};

int main() {
   cout << "OOP345 NBB - Feb06" << endl;
   Add add;
   int a = 10;

   int res;
   for(int i=0;i<20;i++)
    res = add(a, 50);

   cout << add.noOfCalls() <<  endl;



   return 0;
}

