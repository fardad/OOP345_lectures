
class Student {
private:
   int stno; // class scope
public:
   void display();
   Student();
   Student( int s );


};
// external linkage
extern const int MinPassGrade;   // kind of like a prototype of a item