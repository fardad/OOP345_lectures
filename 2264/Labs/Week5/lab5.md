# OOP345 Lab — Passing Logic to Functions

## Topic

Week 5 — Functions

This lab practises passing decision-making logic to functions using:

* pointer to function
* functor / function object
* lambda expression

## Estimated Time

50 minutes

## Learning Outcomes

After completing this lab, you will be able to:

* pass a regular function to another function using a function pointer
* declare and use a function pointer variable
* create a functor by overloading `operator()`
* write a function template that accepts different callable objects
* use lambda expressions as logic passed to a function
* understand the difference between function pointers, functors, and lambdas

---

# Lab Scenario

You are given a list of student marks.

Your task is to complete a small module that can process the marks using different selection rules.

For example:

* select passing marks
* select failing marks
* count marks in a range
* count marks selected by a lambda expression

The important rule is:

> The processing function must not know the selection rule.
> The selection rule must be passed to the function.

---

# Files

You are given the following files:

```text
main.cpp        // provided tester, do not modify
selection.h    // complete this file
selection.cpp  // complete this file
```

You must only modify:

```text
selection.h
selection.cpp
```

Do not modify `main.cpp`.

The `main.cpp` file is a tester program. Your task is to complete the module so the provided tester compiles and produces the expected output.

---

# Part 1 — Header File

Create a header file called:

```text
selection.h
```

Add the header guard:

```cpp
#ifndef SENECA_SELECTION_H
#define SENECA_SELECTION_H
```

At the end of the file, close the header guard:

```cpp
#endif
```

All your work must be inside the `seneca` namespace.

---

# Part 2 — Regular Selection Functions

In `selection.h`, add prototypes for two functions:

```cpp
bool isPass(int mark);
bool isFail(int mark);
```

In `selection.cpp`, implement these functions.

## `isPass`

Returns `true` if the mark is 50 or more.

## `isFail`

Returns `true` if the mark is less than 50.

---

# Part 3 — Function Pointer Version of `printSelected`

In `selection.h`, add the prototype for this function:

```cpp
void printSelected(const int marks[], std::size_t size, bool (*selector)(int));
```

This function receives:

* an array of marks
* the size of the array
* a pointer to a function that receives an `int` and returns a `bool`

In `selection.cpp`, implement the function so it prints only the marks accepted by the selector.

The selector is called like this:

```cpp
selector(marks[i])
```

If the selector returns `true`, print the mark.

Example logic:

```cpp
if (selector(marks[i])) {
   // print the mark
}
```

Each selected mark should be printed followed by one space.

Print a newline at the end of the function.

---

# Part 4 — Functor Class

In `selection.h`, create a class called `InRange`.

This class stores a minimum and maximum acceptable mark.

```cpp
class InRange {
   int m_min{};
   int m_max{};
public:
   InRange(int min, int max);
   bool operator()(int mark) const;
};
```

In `selection.cpp`, implement:

## Constructor

```cpp
InRange(int min, int max);
```

The constructor stores the received minimum and maximum values in the attributes.

## Function Call Operator

```cpp
bool operator()(int mark) const;
```

This function returns `true` if the mark is between `m_min` and `m_max`, inclusive.

For example, if the object is created like this:

```cpp
seneca::InRange range(70, 90);
```

Then:

```cpp
range(75)
```

should return `true`, and:

```cpp
range(95)
```

should return `false`.

---

# Part 5 — Function Template: `countSelected`

In `selection.h`, create a function template called `countSelected`.

This function must receive:

* an array of marks
* the size of the array
* a selector

The selector can be:

* a regular function
* a function pointer variable
* a functor
* a lambda expression

The function returns how many marks are accepted by the selector.

Prototype and implementation:

```cpp
template <typename Selector>
int countSelected(const int marks[], std::size_t size, Selector selector) {
   int count{};

   for (std::size_t i = 0; i < size; i++) {
      if (selector(marks[i])) {
         count++;
      }
   }

   return count;
}
```

Because this is a function template, its implementation must be written in the header file.

---

# Provided Tester: `main.cpp`

Do not modify this file.

```cpp
#include <iostream>
#include "selection.h"

using namespace std;

void printTitle(const char* title) {
   cout << endl;
   cout << title << endl;
   cout << "------------------------------" << endl;
}

int main() {
   int marks[]{ 45, 72, 88, 39, 60, 91, 50, 27, 76 };
   size_t size = sizeof(marks) / sizeof(marks[0]);

   printTitle("All marks");
   for (size_t i = 0; i < size; i++) {
      cout << marks[i] << " ";
   }
   cout << endl;

   printTitle("Passing marks using regular function");
   seneca::printSelected(marks, size, seneca::isPass);

   printTitle("Failing marks using regular function");
   seneca::printSelected(marks, size, seneca::isFail);

   printTitle("Passing marks using function pointer variable");
   bool (*selector)(int) = seneca::isPass;
   seneca::printSelected(marks, size, selector);

   printTitle("Counting marks between 70 and 90 using functor");
   seneca::InRange between70and90(70, 90);
   cout << "Count: " << seneca::countSelected(marks, size, between70and90) << endl;

   printTitle("Counting excellent marks using lambda");
   cout << "Count: " << seneca::countSelected(marks, size, [](int mark) {
      return mark >= 80;
   }) << endl;

   printTitle("Counting marks using captured lambda");
   int limit = 60;
   cout << "Count: " << seneca::countSelected(marks, size, [limit](int mark) {
      return mark >= limit;
   }) << endl;

   return 0;
}
```

---

# Expected Output

```text
All marks
------------------------------
45 72 88 39 60 91 50 27 76

Passing marks using regular function
------------------------------
72 88 60 91 50 76

Failing marks using regular function
------------------------------
45 39 27

Passing marks using function pointer variable
------------------------------
72 88 60 91 50 76

Counting marks between 70 and 90 using functor
------------------------------
Count: 3

Counting excellent marks using lambda
------------------------------
Count: 2

Counting marks using captured lambda
------------------------------
Count: 5
```

---

# Checklist

Before submitting, make sure:

* `main.cpp` was not modified
* `selection.h` has a proper header guard
* all required code is inside the `seneca` namespace
* `isPass` returns true for marks 50 and above
* `isFail` returns true for marks below 50
* `printSelected` receives and uses a function pointer
* `InRange` stores the minimum and maximum values
* `InRange::operator()` returns true only for marks inside the range
* `countSelected` is implemented in the header file
* the tester compiles and produces the expected output

---

# Submission

Submit the following files:

```text
selection.h
selection.cpp
```

Do not submit a modified `main.cpp`.

---

# Submission Command On Matrix

```bash
~fardad.soleimanloo/submit 345/labxx/n?? <ENTER>
```

Replace `xx` with the lab number and replace `n??` with your section.

For example:

```bash
~fardad.soleimanloo/submit 345/lab05/naa <ENTER>
```
