#pragma once
#include <iostream>
class Record {
   char* m_data;
public:
   Record( const char* data = "" );
   Record( const Record& other );
   Record( Record&& other );
   Record& operator=( const Record& other );
   Record& operator=(Record&& other );
   virtual ~Record( );
   std::ostream& display( std::ostream& ostr = std::cout )const;
};
std::ostream& operator<<( std::ostream& ostr,
   const Record& R );
