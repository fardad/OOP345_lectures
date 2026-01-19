#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Record.h"
using namespace std;

Record::Record( const char* data ) {
   m_data = new char[strlen( data ) + 1];
   strcpy( m_data, data );
}

Record::Record( const Record& other ) {
   m_data = new char[strlen( other.m_data ) + 1];
   strcpy( m_data, other.m_data );
   clog << "Copied (" << other << ")" << endl;
}

Record::Record( Record&& other ) {
   m_data = other.m_data; // taking ownership of other's data
   other.m_data = nullptr;
   clog << "Moved " << *this << endl;
}
Record& Record::operator=( Record&& other ) {
   if ( this != &other ) {
      clog << "(" << *this << ") is ";
      delete[] m_data; // delete own data
      m_data = other.m_data; // taking ownership of other's data
      other.m_data = nullptr;
      clog << "move assigned to (" << (*this) << ")" <<  endl;
   }
   return *this;
}

Record& Record::operator=( const Record& other ) {
   if ( this != &other ) {
      clog << "Assgined (" << *this << ")";
      delete[] m_data;
      m_data = new char[strlen( other.m_data ) + 1];
      strcpy( m_data, other.m_data );
      clog << " to (" << *this << ")" << endl;
   }
   return *this;
}


Record::~Record( ) {
   delete[] m_data;
}

ostream& Record::display( ostream& ostr )const{
   if ( m_data ) {
      ostr << m_data;
   }
   return ostr;
}

std::ostream& operator<<( std::ostream& ostr, const Record& R ) {
   return R.display( ostr);
}
