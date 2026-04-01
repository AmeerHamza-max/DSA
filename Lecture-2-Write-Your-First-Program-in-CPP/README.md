# C++ Basics Documentation

## Getting Started

C++ is a high-level programming language that needs to be **compiled** into machine-readable binary code before execution. A **compiler** translates the C++ source code into binary.

Example:

```cpp
int a = 1;
int b = 2;
int c = a + b; // Compiler translates this into binary
```

**Additional Info:**

* C++ is an extension of C and supports Object-Oriented Programming (OOP).
* Compilers not only translate code but also check for errors and optimize performance.

---

## IDE (Integrated Development Environment)

To write and run C++ programs, you need an **IDE**.
Common IDEs: Visual Studio, Code::Blocks, CLion, or VS Code with C++ extension.

### Structure of a C++ Program

```cpp
#include <iostream> // include input/output library
using namespace std;

int main() { // Start of the program
    // Code goes here
}
```

* `{}` braces: Everything inside is part of the `int main()` function.
* `int main()` is the entry point of a C++ program.
* Every statement ends with a semicolon `;`.

**Additional Info:**

* Comments (`//` or `/* */`) are ignored by the compiler but help explain code.
* Using `namespace std;` avoids typing `std::` before every standard function.

---

## Printing Output

To print something on the screen, use `cout`:

```cpp
cout << "Hello, World!" << endl;
```

* `cout`: standard output stream.
* `<<`: operator used to send data to `cout`.
* `endl` or `"\n"`: used to move to a new line.

Example:

```cpp
cout << "Hello" << endl;  // New line after Hello
cout << "World\n";        // New line after World
```

**Additional Info:**

* You can print multiple items in one `cout` statement: `cout << a << " " << b << endl;`.
* `cin` is used to take input from the user.

---

## Variables

Variables store data in memory. Every variable has:

1. **Type** – the kind of data stored.
2. **Name** – identifier of the variable.
3. **Memory allocation** – size depends on the type.

### Basic Data Types

| Data Type | Example          | Memory  | Notes                       |
| --------- | ---------------- | ------- | --------------------------- |
| int       | int a = 5;       | 4 bytes | Whole numbers               |
| char      | char ch = 'a';   | 1 byte  | Single character            |
| bool      | bool b = true;   | 1 bit   | true or false               |
| float     | float f = 1.2;   | 4 bytes | Decimal numbers             |
| double    | double d = 1.23; | 8 bytes | More precise decimal number |

### Rules for Variable Names

* Can include letters, digits, and underscores.
* Must start with a letter or underscore.
* Case-sensitive (`abc` and `ABC` are different).
* Cannot reuse the same name in the same scope.

**Additional Info:**

* Constants can be declared using `const` keyword, e.g., `const int MAX = 100;`.
* `auto` keyword lets the compiler decide the variable type.

---

## Example Program

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 123;
    cout << a << endl;

    char b = 'v';
    cout << b << endl;

    bool bl = true;
    cout << bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << d << endl;

    cout << "Size of a is: " << sizeof(a) << endl;
    cout << "Size of b is: " << sizeof(b) << endl;
    cout << "Size of bl is: " << sizeof(bl) << endl;
    cout << "Size of f is: " << sizeof(f) << endl;
    cout << "Size of d is: " << sizeof(d) << endl;

    // char aa='bb'; // ❌ Error: Single quotes can hold only 1 character
}
```

---

## Notes

* `sizeof()` returns the memory size of a variable.
* Cannot assign multiple characters to a `char` type using single quotes. Use `string` for multiple characters.
* `endl` and `"\n"` are interchangeable for moving to a new line.
* `bool` outputs as `1` (true) or `0` (false) in `cout`.
* C++ supports **type casting**, e.g., `int(f)` converts float to integer.
* Always initialize variables to avoid garbage values.
