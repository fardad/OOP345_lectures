## Understanding lvalues and rvalues in C++

### lvalue (locator value)

An **lvalue** refers to an object that occupies a specific memory location. It has an identifiable address, meaning you can take its address using the `&` operator. Examples include:

* Variables
* Dereferenced pointers
* Array elements
* Function calls that return lvalue references

### rvalue (read value)

An **rvalue** is a temporary value that does not persist beyond the expression that uses it. It does not have a persistent memory address and cannot be assigned to. Examples include:

* Literals (e.g., `42`, `3.14`)
* Temporary objects returned by functions
* Expressions like `x + y`

---

## Code Example

```cpp
#include <iostream>

int getValue() {
    return 42; // Returns an rvalue
}

int main() {
    int x = 5;       // 'x' is an lvalue; '5' is an rvalue
    int y = x;       // 'x' is an lvalue; its value is used as an rvalue
    int z = x + y;   // 'x + y' is an rvalue

    int* p = &x;     // '&x' is valid; 'x' is an lvalue

    // Invalid: cannot assign to an rvalue
    // 10 = x;       // Error: lvalue required as left operand of assignment

    // Invalid: cannot take the address of an rvalue
    // int* q = &10; // Error: cannot take the address of an rvalue

    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    return 0;
}
```

**Explanation:**

* `x`, `y`, and `z` are lvalues because they refer to identifiable memory locations.
* `5`, `x + y`, and the return value of `getValue()` are rvalues because they are temporary and do not have a persistent memory address.
* Attempting to assign to an rvalue (e.g., `10 = x;`) or take the address of an rvalue (e.g., `&10`) results in a compilation error.

---

## Key Points

* **lvalues** have identifiable memory addresses and can appear on the left-hand side of an assignment.
* **rvalues** are temporary values that do not have a persistent memory address and typically appear on the right-hand side of an assignment.
* Understanding the distinction between lvalues and rvalues is crucial for grasping concepts like references, move semantics, and efficient resource management in C++.

---

## lvalues, rvalues, and `&&` in C++

### Refresher: lvalue vs. rvalue

* **lvalue**: Has a name and a persistent memory address
  Example: `int x = 5;` → `x` is an lvalue
* **rvalue**: Temporary value; does not have a persistent memory address
  Example: `x + 2` or `42`

---

## Reference Types

| Type               | Can Bind To |
| ------------------ | ----------- |
| `T&` (lvalue ref)  | lvalues     |
| `T&&` (rvalue ref) | rvalues     |

---

## Example: Using `&&` to Handle Rvalues

```cpp
#include <iostream>
#include <string>

void printRef(const std::string& s) {
    std::cout << "Lvalue reference: " << s << '\n';
}

void printRef(std::string&& s) {
    std::cout << "Rvalue reference: " << s << '\n';
}

int main() {
    std::string name = "Seneca";

    printRef(name);          // lvalue: binds to const std::string&
    printRef("Polytechnic"); // rvalue: binds to std::string&&
}
```

### Output:

```
Lvalue reference: Seneca
Rvalue reference: Polytechnic
```

