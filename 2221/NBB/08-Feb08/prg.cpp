#include <iostream>
using namespace std;

class Stack;
class Node {
   int m_data;
   Node* m_next{};
   friend class Stack;
   Node(int data, Node* next) {
      m_data = data;
      m_next = next;
   }
};


class Stack {
   Node* m_top{};
public:
   Stack& push(int data) {
      //            1         2     3
      Node* temp = new Node(data, m_top);
      m_top = temp;
      return *this;
   }
   int pop() {
      int data = m_top->m_data;   //13
      Node* toDel = m_top;
      //m_top = toDel->m_next;
      m_top = m_top->m_next;
      delete toDel;
      return data;
   }
   bool isEmpty()const {
      return m_top == nullptr;
   }
   operator bool()const {
      return m_top != nullptr;
   }
   virtual ~Stack(){
      while (*this) {
         pop();
      }
   }
};


int main() {
   Stack S;
   S.push(10);
   S.push(20);
   S.push(30);
   S.push(40);
   S.push(50);
   S.push(60);
   S.push(70);
   for (int i = 0; i < 4; i++) {
      cout << S.pop() << endl;
   }
   if (S) {
      cout << "Stack is not empty" << endl;
   }
   if (S.isEmpty()) {
      cout << "Stack is Empty" << endl;
   }
   return 0;
}
