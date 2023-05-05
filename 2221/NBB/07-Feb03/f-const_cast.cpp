#include <iostream>
using namespace std;
class Name {
   string m_value;
   int m_noOfPrints{};
public:
   Name(string value);
   ostream& display(ostream& os = std::cout)const {
      int* p = const_cast<int*>(&m_noOfPrints);
      (*p)++;
      return os << m_value;
   }
};

void printName(const Name& C) {
   C.display();
}

int main() {
   return 0;
}
