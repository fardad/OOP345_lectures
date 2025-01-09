#ifndef SENECA_SHPTR_H
#undef SENECA_SHPTR_H
namespace seneca {
   template <typename Type>
   class ShPtr {
      Type* m_ptr{ };
      size_t* m_ptrCnt{  };
      void wipeout( ) { // replace delete
         if ( m_ptrCnt ) (*m_ptrCnt)--;
         if ( m_ptrCnt && *m_ptrCnt == 0 ) {
            delete m_ptr;
            delete m_ptrCnt;
         }
      }
   public:
      ShPtr( Type* ptr = nullptr )
         : m_ptr{ ptr }
         , m_ptrCnt( new size_t( ptr ? 1 : 0 ) ) {
      }
      ShPtr( const ShPtr<Type>& sp ) 
         : m_ptr{ sp.m_ptr }
         , m_ptrCnt{ sp.m_ptrCnt } {
         if ( m_ptr ) (*m_ptrCnt)++;
      }
      ShPtr& operator=( const ShPtr<Type>& obj ) { // copy assign
         if ( this != &obj ) {
            wipeout( ); // wipe out already existing data
            m_ptr = obj.m_ptr; // share addresses
            m_ptrCnt = obj.m_ptrCnt;
            if ( obj.m_ptr ) {
               (*m_ptrCnt)++; // if null, increment add one to counter
            }
         }
         return *this;
      }
      ShPtr( ShPtr<Type>&& dyingObj)noexcept { // move constr
         m_ptr = dyingObj.m_ptr; // share the underlying pointer
         m_ptrCnt = dyingObj.m_ptrCnt;
         dyingObj.m_ptr = nullptr;
         dyingObj.m_ptrCnt = nullptr; // clean the dying object
      }
      ShPtr& operator=( ShPtr<Type>&& dyingObj ) { // move assign
         if ( this != &dyingObj ) {
            wipeout( ); // wipe out already existing data
            m_ptr = dyingObj.m_ptr; // share the underlying pointer
            m_ptrCnt = dyingObj.m_ptrCnt;
            dyingObj.m_ptr = nullptr;
            dyingObj.m_ptrCnt = nullptr; // clean the dying object
         }
         return *this;
      }

      size_t count( ) const {
         return m_ptrCnt? *m_ptrCnt: size_t(0); // *m_ptrCnt
      }

      Type* operator->( ) {
         return m_ptr;
      }

      Type& operator*( ) const {
         return *m_ptr;
      }

      //operator bool( )const {
      //   return m_ptr != nullptr;
      //}

      operator const void* ()const {
         return static_cast<const void*>(m_ptr);
      }

      virtual ~ShPtr( ) {
         wipeout( );
      }
   };
}
#endif // !SENECA_SHPTR_H

