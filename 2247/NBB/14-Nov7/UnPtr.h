#ifndef SENECA_UNPTR_H
#undef SENECA_UNPTR_H
namespace seneca {
   template<typename Type>
   class UnPtr {
      Type* m_ptr{};
   public:
      UnPtr( Type* ptr = nullptr ) :m_ptr{ ptr } { }
      UnPtr( const UnPtr<Type>& ) = delete;
      UnPtr& operator=( const UnPtr<Type>& ) = delete;
      UnPtr(UnPtr<Type>&& up ) noexcept {
         m_ptr = up.m_ptr;
         up.m_ptr = nullptr;
      }
      UnPtr& operator=( UnPtr<Type>&& up ) noexcept{
         if ( this != &up ) {
            delete m_ptr;
            m_ptr = up.m_ptr;
            up.m_ptr = nullptr;
         }
         return *this;
      }
      Type& operator*( ) {
         return *m_ptr;
      }
      Type* operator->( ) {
         return m_ptr;
      }
      operator const void* () const {
         return m_ptr;
      }
      virtual ~UnPtr( ) {
         delete m_ptr;
      }
   };
}
#endif // !SENECA_UNPTR_H


