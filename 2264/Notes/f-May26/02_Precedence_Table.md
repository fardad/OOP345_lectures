# C++ Operator Precedence Table

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
