#include <iostream>
using namespace std;
class Stack;

class Node {
   Node* m_next = nullptr;
   int m_data;
   Node(int data, Node* next = nullptr) {
      m_next = next;
      m_data = data;
   }
   friend class Stack;
};

class Stack {
   Node* top = nullptr;
public:
   Stack& push(int data) {
      top = new Node(data, top);
      return *this;
   }
   int pop() {
      int val;
      val = top->m_data;
      Node* todel = top;
      top = top->m_next;
      delete todel;
      return val;
   }
   operator bool() {
      return top != nullptr;
   }
   virtual ~Stack() {
      while (*this) {
         pop();
      }
   }
};

int main() {
   Stack d;
   d.push(50).push(70).push(100);
   while (d) {
      cout << d.pop() << endl;
   }
   return 0;
}