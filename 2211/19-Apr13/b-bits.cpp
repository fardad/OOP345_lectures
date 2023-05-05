#include <iostream>
using namespace std;
struct EmpSpecs {             
   unsigned age : 7;
   unsigned empno : 20;
   unsigned married : 1;
   unsigned depNo : 4;
   EmpSpecs(unsigned age, unsigned empno, bool married, unsigned depNo) {
      this->age = age;
      this->empno = empno;
      this->married = married;
      this->depNo = depNo;
   }
};
class Employee {
   EmpSpecs sp;
public:
   Employee(unsigned age, unsigned empno, bool married, unsigned depNo):
      sp(age, empno, married, depNo){
   }
};
int main() {
   cout << sizeof(EmpSpecs) << endl;
   return 0;
}