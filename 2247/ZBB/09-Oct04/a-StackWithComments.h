#pragma once
#ifndef SENECA_STACK_H
#define SENECA_STACK_H
namespace seneca {
   
   template <typename type>
   class Stack;


   template <typename type>
   class Node {
      type m_data{};
      Node* m_next{};
      Node( ) = default;
      Node( const type& data, Node* next ) {
         m_data = data;
         m_next = next;
      }
      friend class Stack<type>;
   };

   template<typename type>
   class Stack {
      Node<type>* m_top{};
   public:
      Stack( ) = default;
      // Students practice to un-delete the following
      Stack( const Stack<type>& ) = delete;
      Stack<type>& operator=( const Stack<type>& ) = delete;
      Stack( Stack<type>&& ) = delete;
      Stack<type>& operator=( Stack<type>&& ) = delete;

      void push( const type& data ) {
        /* Node<type>* temp = new Node;
         temp->m_data = data;
         temp->m_next = m_top;*/
         Node<type>* temp = new Node(m_data, m_top);
         m_top = temp;
      }
      type pop( ) {
         // better not to do this so the program can crash 
         // if logic sucks...
         // type ret{};
         //if ( m_top ) {
         //   ret = m_top->m_data;
         //   Node<type>* toDel = m_top;
         //   m_top = m_top->m_next;
         //   delete toDel;
         //}
         //return ret;
         type ret{} = m_top->m_data;
         Node<type>* toDel = m_top;
         m_top = m_top->m_next;
         delete toDel;
         return ret;
      }
      bool isEmpty( )const {
         return m_top == nullptr;
      }
      virtual ~Stack( ) {
         while ( !isEmpty( ) ) {
            pop( );
         }
 /*        Node<type>* todel{}
         while ( m_top ) {
            todel = m_top;
            m_top = m_top->m_next;
            delete todel;
         }*/
      }

   };


}
#endif