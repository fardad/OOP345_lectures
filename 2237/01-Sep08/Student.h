#pragma once
class Student {
   int stno; // class scope
public:
   void display( );
   Student( );
};

extern const int MinPassGrade; // makes the file scope global

