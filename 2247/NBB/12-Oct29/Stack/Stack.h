#ifndef SDDS_STACK_H__
#define SDDS_STACK_H__
template <typename T>
class Stack;
template <typename T>
class Node {
   Node<T>* m_next = nullptr;
   T m_data;
   Node(T data, Node<T>* next = nullptr) {
      m_next = next;
      m_data = data;
   }
   friend class Stack<T>;
};
template <typename T>
class Stack {
   Node<T>* top = nullptr;
public:
   Stack<T>& push(T data) {
      top = new Node<T>(data, top);
      return *this;
   }
   T pop() {
      T val;
      val = top->m_data;
      Node<T>* todel = top;
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


#endif // ! SDDS_STACK_H__
