# Week 4 – Expressions

## 1. Introduction
Expressions are the building blocks of computation in C++.  
They are made up of **operators** and **operands**, and they produce results (sometimes with side effects).  

Why should we care? Because expressions control how our program behaves, how data gets manipulated, and even how sneaky bugs appear when we misunderstand evaluation order.  

*"C [and hence C++] has an unusually rich set of operators that provide access to most of the operations provided by the underlying hardware."* — Harbison and Steele (2002)

---

## 2. Value Categories
Every expression in C++ belongs to a **value category**. This tells us whether an expression refers to an object in memory, a temporary, or something that’s about to expire.  

- **lvalue (locator value)** → has a memory location (like a variable).  
- **prvalue (pure rvalue)** → temporary value, no storage (like `3 + 4`).  
- **xvalue (expiring value)** → object that will soon be destroyed (like `std::move(x)`).  
- **glvalue** = generalized lvalue = lvalue or xvalue.  
- **rvalue** = prvalue or xvalue.  
![](expressions.png)

Example:

```cpp
// value_categories.cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;          // x is an lvalue
    cout << x << endl;   // 'x' refers to a memory location

    int y = x + 5;       // (x + 5) is a prvalue
    cout << y << endl;

    int&& z = x + 5;     // result of (x + 5) materializes into an xvalue
    cout << z << endl;

    return 0;
}
```

---

## 3. Operator Precedence
Expressions can quickly get messy. C++ defines a strict **precedence and associativity** table for operators.  

- High precedence: evaluated first.  
- Associativity decides direction (left → right or right → left).  
- Parentheses `()` always override precedence.  

Example:

```cpp
// precedence.cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2 + 3 * 4;   // Multiplication first: 2 + (3*4) = 14
    int y = (2 + 3) * 4; // Parentheses force addition first: 20

    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}
```

---


### Operator Precedence Table

| Precedence | Class        | Operators                                                                 | Associativity   |
|------------|-------------|----------------------------------------------------------------------------|-----------------|
| 18         | Primary      | name, literal, `::` (scope resolution)                                     | left-to-right   |
| 17         | Postfix      | `[]`, `()`, `.`, `->`, `++`, `--`, `typeid`, `const_cast`, `dynamic_cast`, `reinterpret_cast`, `static_cast` | left-to-right   |
| 16         | Prefix/Unary | `++`, `--`, `sizeof`, `!`, `~`, `-`, `+`, `&`, `*`, `new`, `delete`, `alignof`, `noexcept`, cast `(type)` | right-to-left   |
| 15         | Binary       | `.*`, `->*`                                                               | left-to-right   |
| 14         | Multiplicative | `*`, `/`, `%`                                                           | left-to-right   |
| 13         | Additive     | `+`, `-`                                                                 | left-to-right   |
| 12         | Shift        | `<<`, `>>`                                                               | left-to-right   |
| 11         | Relational   | `<`, `>`, `<=`, `>=`                                                      | left-to-right   |
| 10         | Equality     | `==`, `!=`                                                               | left-to-right   |
| 9          | Bitwise AND  | `&`                                                                      | left-to-right   |
| 8          | Bitwise XOR  | `^`                                                                      | left-to-right   |
| 7          | Bitwise OR   | `|`                                                                      | left-to-right   |
| 6          | Logical AND  | `&&`                                                                     | left-to-right   |
| 5          | Logical OR   | `||`                                                                     | left-to-right   |
| 4          | Ternary      | `?:`                                                                     | right-to-left   |
| 3          | Assignment   | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `>>=`, `<<=`, `&=`, `^=`, `|=`         | right-to-left   |
| 2          | Exception    | `throw`                                                                  | left-to-right   |
| 1          | Sequencing   | `,`                                                                      | left-to-right   |

## 4. Postfix Expressions

### Array Subscript
Access an element in an array by offset:  
```cpp
// subscript.cpp
#include <iostream>
using namespace std;

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    cout << "a[2] = " << a[2] << endl;
    return 0;
}
```

### Member Selection
- **Direct (`.`)** → object.member  
- **Indirect (`->`)** → pointer->member  

```cpp
// member_selection.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p{1, 2};
    cout << p.x << "," << p.y << endl; // direct

    Point* ptr = &p;
    cout << ptr->x << "," << ptr->y << endl; // indirect
    return 0;
}
```

### Postfix Increment/Decrement
Happens *after* evaluation. Result is a prvalue.

```cpp
// postfix.cpp
#include <iostream>
using namespace std;

int main() {
    int i = 10;
    cout << i++ << endl;  // prints 10, then increments
    cout << i << endl;    // prints 11
    return 0;
}
```

---

## 5. Prefix Expressions
Increment/Decrement happens *before* evaluation. Result is an lvalue.

```cpp
// prefix.cpp
#include <iostream>
using namespace std;

int main() {
    int i = 10;
    cout << ++i << endl;  // increments to 11, then prints 11
    cout << i << endl;    // now 11
    return 0;
}
```

---

## 6. Unary Expressions

### `sizeof`
Evaluates size in bytes (compile-time).

```cpp
// sizeof.cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    cout << sizeof(int) << " " << sizeof(x) << endl;
    return 0;
}
```

### Logical Negation
```cpp
// logical.cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    cout << !x << endl;   // true (1), since x == 0
    x = 5;
    cout << !x << endl;   // false (0), since x != 0
    return 0;
}
```

### Address-of and Indirection
```cpp
// address_indirection.cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* p = &x;      // address-of
    cout << *p << endl; // indirection
    return 0;
}
```

### Casts
Use C++-style casts instead of old-school C-style.  

```cpp
// cast.cpp
#include <iostream>
using namespace std;

int main() {
    double pi = 3.14159;
    int approx = static_cast<int>(pi);
    cout << approx << endl;
    return 0;
}
```

---

## 7. Binary Expressions

### Arithmetic
```cpp
// arithmetic.cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    cout << a + b << " " << a - b << " " << a * b << " " << a / b << " " << a % b << endl;
    return 0;
}
```

### Relational
```cpp
// relational.cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 7;
    cout << (a < b) << " " << (a == b) << " " << (a != b) << endl;
    return 0;
}
```

### Logical with Short-Circuiting
```cpp
// logical_and_or.cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    if (i != 0 && 10 / i > 1)  // second part not evaluated
        cout << "Won't crash" << endl;
    else
        cout << "Safe!" << endl;
    return 0;
}
```

### Assignment
```cpp
// assignment.cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    a = b = c = 5;
    cout << a << " " << b << " " << c << endl;
    a += 2;
    cout << a << endl;
    return 0;
}
```

### Comma Operator
```cpp
// comma.cpp
#include <iostream>
using namespace std;

int main() {
    int x, y;
    x = (y = 5, y + 2);  // evaluates y=5, then y+2
    cout << x << endl;   // 7
    return 0;
}
```

---

## 8. Ternary Expressions
The conditional operator is a compact `if-else`.  

```cpp
// ternary.cpp
#include <iostream>
using namespace std;

int main() {
    int x = -10;
    int sign = (x < 0 ? -1 : 1);
    cout << "sign = " << sign << endl;
    return 0;
}
```

---

## 9. Summary
- Expressions = operators + operands = computation.  
- Value categories explain *where values live*.  
- Precedence and associativity dictate evaluation order.  
- Parentheses are your best friend for readability.  
- Good practice: keep expressions simple and clear.  

---

**End of Week 4 Lecture – Expressions**
