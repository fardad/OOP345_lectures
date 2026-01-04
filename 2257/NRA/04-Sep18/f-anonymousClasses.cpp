// Anonymous instance
struct {
   char shortName[7];
   char fullName[41];
} name;

// Anonymous with typedef (synonym)
typedef struct {
   unsigned number;
   char desc[41];
} Course; // "Course" is now a synonym for this struct


class Student {
   struct {
      string first;
      string last;
   } name;
   size_t st_no;
   .....
};