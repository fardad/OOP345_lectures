### Character Types in C++

#### `char`

* The basic character type in C++.
* Size: **1 byte** (usually 8 bits).
* Represents a single character, typically using the ASCII character set or UTF-8.
* Whether it's signed or unsigned is **implementation-defined**.
* Commonly used in strings such as `char[]` and `std::string`.

#### `signed char`

* An explicitly **signed** 8-bit integer.
* Range: typically -128 to 127.
* Suitable for arithmetic or binary data requiring signed interpretation.
* **Distinct type** from `char`.

#### `unsigned char`

* An explicitly **unsigned** 8-bit integer.
* Range: 0 to 255.
* Frequently used for raw byte manipulation, such as working with binary files or image data.
* Also a **distinct type** from `char`.

> Although `char`, `signed char`, and `unsigned char` are all 1 byte in size, they are treated as **three different types** in C++.

---

### Unicode Character Types

#### `wchar_t`

* Used to store wide characters beyond the ASCII set.
* Size: **implementation-defined** (commonly 2 bytes on Windows and 4 bytes on Linux).
* May represent UTF-16 or UTF-32 code units depending on the platform.
* Considered a legacy option; `char16_t` and `char32_t` are preferred in modern C++.

#### `char16_t`

* Introduced in C++11.
* A fixed-width **16-bit** type.
* Used for **UTF-16** encoded text.
* May require surrogate pairs for characters outside the Basic Multilingual Plane (BMP).

#### `char32_t`

* Also introduced in C++11.
* A fixed-width **32-bit** type.
* Used for **UTF-32** encoded text.
* Each value uniquely represents a full Unicode code point without the need for surrogate pairs.

---

### Summary Table

| Type            | Size         | Signed                 | Typical Use                         |
| --------------- | ------------ | ---------------------- | ----------------------------------- |
| `char`          | 1 byte       | Implementation-defined | Basic characters (ASCII/UTF-8)      |
| `signed char`   | 1 byte       | Yes                    | Small signed integers, binary data  |
| `unsigned char` | 1 byte       | No                     | Raw byte manipulation               |
| `wchar_t`       | 2 or 4 bytes | Implementation-defined | Wide characters (platform-specific) |
| `char16_t`      | 2 bytes      | No                     | UTF-16 encoded text                 |
| `char32_t`      | 4 bytes      | No                     | UTF-32 encoded text                 |

