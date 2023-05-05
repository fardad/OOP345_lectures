#ifndef SDDS_STACK_H__
#define SDDS_STACK_H__
namespace sdds {
   // implement the rule of 5 in oop345Works Repo, multiple commits and get 
   // 5% for your midterm.

   template <typename T>
   class Stack;

   template <typename T>
   class Node {
      Node<T>* m_next = nullptr;
      T m_data;
      Node(T data, Node<T>* next) {
         m_next = next;
         m_data = data;
      }
      friend class Stack<T>;
   };
  
   template <typename T>
   class Stack {
      Node<T>* m_top{};
      size_t m_depth{};
   public:
      Stack<T>& push(T data) {
         m_top = new Node<T>(data, m_top);
         m_depth++;
         return *this;
      }
      T pop() {
         T val;
         val = m_top->m_data;
         Node<T>* todel = m_top;
         m_top = m_top->m_next;
         delete todel;
         m_depth--;
         return val;
      }
      bool isEmtpy()const {
         return m_top == nullptr;
      }
      operator bool()const {
         return m_top != nullptr;
      }
      virtual ~Stack() {
         Node<T>* todel = m_top;
         while (m_top != nullptr) {
            m_top = m_top->m_next;
            delete todel;
            todel = m_top;
         }
      }
      size_t depth()const {
         return m_depth;
      }
   };
}

#endif // ! SDDS_STACK_H__
