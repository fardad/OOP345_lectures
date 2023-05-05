#ifndef SDDS_STACK_H__
#define SDDS_STACK_H__

template <typename T>
class Stack;

template <typename T>
class Node {
   Node<T>* m_next = nullptr;
   T m_data;
   static size_t num;

   Node(T data, Node<T>* next) {
      m_next = next;
      m_data = data;
      num++;
   }
   ~Node() {
      num--;
   }
   friend class Stack<T>;
};
template<typename T>
size_t Node<T>::num = 0;


template <typename T>
class Stack {
   Node<T>* top = nullptr;
public:
   Stack<T>& push(T data) {
      top = new Node<T>(data, top);
      return *this;
   }
   T pop() {
      T data;
      data = top->m_data;
      Node<T>* toDel = top;
      top = top->m_next;
      delete toDel;
      return data;
   }
   bool isEmpty()const {
      return top == nullptr;
   }
   operator bool()const {
      return top != nullptr;
   }
   size_t depth()const {
      return Node<T>::num;
   }
   /*virtual ~Stack() {
      while (!isEmpty()) pop();
   }*/
   virtual ~Stack() {
      Node<T>* toDel = top;
      while (top != nullptr) {
         top = top->m_next;
         delete toDel;
         toDel = top;
      }
   }
};

#endif 