#include "module.h"

const int MinPassGrade = 50;  // global scope

const int MaxStdNoLength = 9; // file scope

static const int semester = 1; // file scope only (internal linkage)

void Student::display() {
}

Student::Student() {
}

Student::Student( int s ) {
}

