// typedef alreadyExistingType NewType;

struct Student {
   double m_gpa;
   char m_name[81];
}   ;

typedef unsigned char age;
typedef const unsigned long long int* culli_p;
typedef int* int_p;


void foo( ) {
   culli_p p;
   int* a, * b, * c;
   int_p a, b, c;
   Student S;
   age theAge;
}
