#pragma once
#ifndef SENECA_STACK_H
#define SENECA_STACK_H
namespace seneca {
   template <typename type>
   class Stack;
   template <typename type>
   class Node {
      type m_data;
      Node<type>* m_next;
      Node(const type& data, Node<type>* next = nullptr ) :m_data{ data }, m_next{ next } { }
      friend class Stack<type>;
   };
   template<typename type>
   class Stack {
      Node<type>* m_top{};
   public:
      Stack( ) = default;
      Stack( const Stack<type>& ) = delete;
      Stack<type>& operator=( const Stack& cp ) = delete;
      void push( const type& data ) {
         Node<type>* newNode = new Node<type>( data, m_top );
         m_top = newNode;
      }
      bool isEmpty( )const {
         return m_top == nullptr;
      }
      type pop( ) {
         type toRet{ };
         if ( m_top ) {
            toRet = m_top->m_data;
            Node<type>* toDel = m_top;
            m_top = m_top->m_next;
            delete toDel;
         }
         return toRet;
      }
      virtual ~Stack( ) {
         while (!isEmpty() ) {
            pop( );
         }
      }
   };



}
#endif // !SENECA_STACK_H
