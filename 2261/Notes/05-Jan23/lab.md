## OOP345 Lab: “Name” — Rule of Five + Stream Insertion (50 minutes)

### Learning outcomes

By the end of this lab, a student can:

* Manage a dynamic C-string safely in a class
* Implement the **Rule of Five**
* Provide safe copying/moving behaviour
* Make a class **insertable into `std::ostream`** (via `operator<<` calling a member)

---

## Specifications

### 1) Provided utility (given)

You may use the provided function to manage dynamic allocation/copying:

```cpp
void aloCpy(char*& des, const char* src) {
    delete[] des;
    des = nullptr;

    if (src) {
        size_t l = 0;
        while (src[l++] != '\0');     // l becomes (length + 1), including the null
        des = new char[l];

        for (l = 0; (des[l] = src[l]) != '\0'; l++); // copy incl. '\0'
    }
}
```

* Use it whenever you need to copy a C-string into your attribute.



## 2) Module structure

Create these files:

* `Name.h`
* `Name.cpp`
* `main.cpp` 

---

## 3) The `Name` class requirements

### Attribute

* `char* m_value;`  (dynamic C-string)

### Construction

* The class **must be instantiable only with a provided name**:

  * A constructor that receives `const char*` (no default construction).
  * If the incoming pointer is `nullptr` or points to an empty string, the object becomes an **empty name** (decide one of these policies and state it clearly):

    * either store `nullptr`
    * or store an allocated empty string `""`

(Choose one policy for the lab; both are acceptable as long as the rest is consistent.)

### Display / ostream insertion

* Implement a member function:

  * `std::ostream& display(std::ostream& os) const;`
* Implement a **non-member** insertion operator that calls `display`:

  * `std::ostream& operator<<(std::ostream& os, const Name& N);`

*(No printing inside the class other than through `display`.)*

### Rule of Five (mandatory)

Implement all of the following:

* Destructor
* Copy constructor
* Copy assignment operator
* Move constructor
* Move assignment operator

Requirements:

* No memory leaks
* No double deletes
* Copy must be **deep copy**
* Move must “steal” ownership and leave the source in a safe empty state

---

## 4) Behaviour rules

* `display` prints:

  * the stored name if it exists
  * otherwise prints a clear empty representation (pick one and specify it), e.g.:

    * prints nothing
    * prints `[No Name]`
    * prints `""`

Keep it consistent for marking/testing.

---

## 5) Lab tasks (what students do)

* Create the class skeleton in `Name.h`
* Implement all Rule-of-Five members in `Name.cpp`
* Use `aloCpy` in copy operations (and anywhere else you want to replace content)
* Implement `display`
* Implement `operator<<` in `Name.cpp` (or `Name.cpp` bottom)

---

## 7) “What to test” checklist 

(Just a checklist for now—no solution code.)

* Construct a `Name` and print it with `cout << obj`
* Copy construct: `Name b = a;` then modify `a` (ensure `b` unchanged)
* Copy assign: `b = a;` including self-assign `a = a;`
* Move construct: `Name b = std::move(a);` ensure `a` is safe/empty
* Move assign: `b = std::move(a);` ensure cleanup happens and `a` safe
* Stress test with multiple assignments in a row to catch leaks/double deletes
