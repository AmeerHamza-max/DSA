# C++ Switch Statements & Functions — Complete Beginner's Guide

> By the end of this guide, you will **fully understand** switch statements and functions in C++ — with real examples, common mistakes, and DSA-ready patterns.

---

## Table of Contents

1. [Switch Statement](#1-switch-statement)
2. [Nested Switch](#2-nested-switch)
3. [Switch with Loops & exit()](#3-switch-with-loops--exit)
4. [Switch vs If-Else](#4-switch-vs-if-else)
5. [Functions in C++](#5-functions-in-c)
6. [Types of Functions](#6-types-of-functions)
7. [Scope of Variables](#7-scope-of-variables)
8. [Function Call Stack](#8-function-call-stack)
9. [Pass by Value](#9-pass-by-value)
10. [Practice Problems](#10-practice-problems)

---

## 1. Switch Statement

### What is a Switch Statement?

A `switch` statement is a cleaner alternative to a long chain of `if-else if-else` when you're checking **one variable against multiple fixed values**.

### Syntax

```cpp
switch (expression) {
    case constant1:
        // code
        break;
    case constant2:
        // code
        break;
    default:
        // code when nothing matches
}
```

### Real-World Analogy

Think of a TV remote. You press button 1 → Channel 1, button 2 → Channel 2, any unknown button → nothing happens (default).

### Example 1 — Integer Switch

```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 2;
    switch (num) {
        case 1:
            cout << "First" << endl;
            break;
        case 2:
            cout << "Second" << endl;   // ✅ This runs
            break;
        default:
            cout << "It is default case" << endl;
    }
    return 0;
}
```

**Output:** `Second`

### Example 2 — Character Switch

```cpp
#include <iostream>
using namespace std;

int main() {
    char ch = 'a';
    switch (ch) {
        case 'b':
            cout << "Character b" << endl;
            break;
        case 'a':
            cout << "Character a" << endl;   // ✅ This runs
            break;
        default:
            cout << "It is default case" << endl;
    }
    return 0;
}
```

**Output:** `Character a`

### ⚠️ Important Rules

| Rule | Explanation |
|------|-------------|
| `break` is required | Without `break`, execution "falls through" to the next case |
| Cases must be constants | `case x+1:` where x is a variable is NOT allowed |
| Works with `int` and `char` only | Cannot use `float`, `string`, or expressions |
| `default` is optional | But always include it as a safety net |
| `continue` is NOT valid in switch | `continue` only works in loops |

### Fall-Through Behavior (No `break`)

```cpp
int num = 1;
switch (num) {
    case 1:
        cout << "One" << endl;
        // no break — falls through!
    case 2:
        cout << "Two" << endl;
        break;
    case 3:
        cout << "Three" << endl;
        break;
}
```

**Output:**
```
One
Two
```

Both case 1 and case 2 run because there's no `break` after case 1. This is called **fall-through** — usually a bug, but occasionally used intentionally.

---

### Example 3 — Calculator using Switch

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter values of A and B: ";
    cin >> a >> b;

    char op;
    cout << "Enter operation (+, -, *, /, %): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            if (b != 0)
                cout << a / b << endl;
            else
                cout << "Cannot divide by zero!" << endl;
            break;
        case '%':
            cout << a % b << endl;
            break;
        default:
            cout << "Please enter a valid operation" << endl;
    }
    return 0;
}
```

---

### Example 4 — Currency Note Counter (DSA-style problem)

**Problem:** Given an amount, print how many notes of 100, 50, 20, 10, and 1 are needed.

```cpp
#include <iostream>
using namespace std;

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int denominations[] = {100, 50, 20, 10, 1};
    int numDenominations = 5;

    cout << "Notes breakdown:" << endl;

    for (int i = 0; i < numDenominations; i++) {
        int noteValue = denominations[i];
        int noteCount = amount / noteValue;
        amount = amount % noteValue;

        switch (noteValue) {
            case 100:
                cout << "100 rupee notes: " << noteCount << endl;
                break;
            case 50:
                cout << "50 rupee notes:  " << noteCount << endl;
                break;
            case 20:
                cout << "20 rupee notes:  " << noteCount << endl;
                break;
            case 10:
                cout << "10 rupee notes:  " << noteCount << endl;
                break;
            case 1:
                cout << "1 rupee coins:   " << noteCount << endl;
                break;
        }
    }
    return 0;
}
```

**Sample Input:** `285`
**Output:**
```
100 rupee notes: 2
50 rupee notes:  1
20 rupee notes:  1
10 rupee notes:  1
1 rupee coins:   5
```

---

## 2. Nested Switch

A switch inside another switch is called a **nested switch**. Each switch has its own set of cases and they don't interfere with each other.

```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 1;
    char ch = '1';

    switch (ch) {
        case '1':
            switch (num) {        // Inner switch
                case 1:
                    cout << "Value of num is " << num << endl;
                    break;
            }
            cout << "Outer case '1'" << endl;
            break;
        case '2':
            cout << "Second" << endl;
            break;
        default:
            cout << "Default case" << endl;
    }
    return 0;
}
```

**Output:**
```
Value of num is 1
Outer case '1'
```

---

## 3. Switch with Loops & exit()

You can combine `switch` with `while` loops to create menus. Use `exit(0)` from `<cstdlib>` to terminate the program entirely.

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice = 1;

    while (true) {
        switch (choice) {
            case 1:
                cout << "Running option 1..." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
        exit(0);   // Terminates the entire program
    }
    return 0;
}
```

> **`exit(0)` vs `break`:**
> - `break` exits only the switch or loop it's inside.
> - `exit(0)` terminates the **entire program** immediately.

---

## 4. Switch vs If-Else

```
If-Else Chain:              Switch Statement:
─────────────────           ─────────────────────────
if (condition)      →       switch (expression) {
else if (condition) →           case value1:
else if (condition) →           case value2:
else                →           default:
```

| Feature | if-else | switch |
|--------|---------|--------|
| Expression type | Any boolean | Only `int` or `char` |
| Ranges | ✅ (`x > 5`) | ❌ (only exact values) |
| Readability | Harder with many options | Much cleaner |
| Speed | Checks each condition | Jumps directly to case |
| `continue` support | ✅ (in loops) | ❌ Not valid |

**Use `switch` when:** you check one variable against many specific values.
**Use `if-else` when:** you need range checks or complex boolean conditions.

---

## 5. Functions in C++

### What is a Function?

A function is a **named block of code** that performs a specific, well-defined task. You write it once and call it anywhere.

### Why Use Functions?

Without functions (bulky code):
```cpp
// Computing power of 2^3
int ans1 = 1;
for (int i = 1; i <= 3; i++) ans1 *= 2;
cout << ans1;

// Computing power of 5^4 — same code again!
int ans2 = 1;
for (int i = 1; i <= 4; i++) ans2 *= 5;
cout << ans2;
```

With functions (clean, reusable):
```cpp
int power(int base, int exp) {
    int ans = 1;
    for (int i = 1; i <= exp; i++) ans *= base;
    return ans;
}

cout << power(2, 3);   // 8
cout << power(5, 4);   // 625
```

✅ Less repetition. ✅ More readable. ✅ Easy to fix bugs in one place.

### Anatomy of a Function

```
return_type  function_name ( parameters )
    ↓              ↓              ↓
   int           power     (int a, int b)
{
    // function body
    return ans;   ← must match return_type
}
```

| Part | Meaning |
|------|---------|
| `return_type` | What data type the function gives back (`int`, `void`, `bool`, etc.) |
| `function_name` | The name you call it by |
| `parameters` | Inputs the function needs |
| `return` | Sends a value back to the caller |
| `void` | Use when the function doesn't return anything |

---

## 6. Types of Functions

### Type 1 — With Parameters and Return Value

```cpp
#include <iostream>
using namespace std;

int power(int a, int b) {
    int ans = 1;
    for (int i = 1; i <= b; i++) {
        ans = ans * a;
    }
    return ans;
}

int main() {
    cout << power(2, 3) << endl;   // Output: 8
    cout << power(5, 4) << endl;   // Output: 625
    return 0;
}
```

### Type 2 — Without Parameters (Reads Inside)

```cpp
#include <iostream>
using namespace std;

int power() {
    int a, b;
    cin >> a >> b;    // Input happens inside the function
    int ans = 1;
    for (int i = 1; i <= b; i++) {
        ans = ans * a;
    }
    return ans;
}

int main() {
    int ans1 = power();
    cout << "Power = " << ans1 << endl;
    int ans2 = power();
    cout << "Power = " << ans2 << endl;
    return 0;
}
```

### Type 3 — Void Function (No Return)

```cpp
#include <iostream>
using namespace std;

void printCounting(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "Number = " << i << endl;
    }
    return;   // Optional in void functions
}

int main() {
    int n;
    cin >> n;
    printCounting(n);
    return 0;
}
```

### Type 4 — Bool Function (Returns True/False)

```cpp
#include <iostream>
using namespace std;

bool isEven(int a) {
    if (a & 1) {    // Bitwise AND: checks last bit
        return false;   // Odd
    }
    return true;    // Even
}

int main() {
    int num;
    cin >> num;
    if (isEven(num)) {
        cout << "Number is Even" << endl;
    } else {
        cout << "Number is Odd" << endl;
    }
    return 0;
}
```

### Type 5 — Function Calling Another Function (nCr example)

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

int nCr(int n, int r) {
    int numerator   = factorial(n);
    int denominator = factorial(r) * factorial(n - r);
    return numerator / denominator;
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << "nCr = " << nCr(n, r) << endl;
    return 0;
}
```

**Input:** `5 2`
**Output:** `nCr = 10`

### Type 6 — Direct cout in Function Call

```cpp
// You can directly print the return value without storing it
cout << "Power = " << power(2, 5) << endl;
```

---

## 7. Scope of Variables

**Scope** = where a variable can be seen and used.

```cpp
#include <iostream>
using namespace std;

int globalVar = 100;    // Global scope: accessible everywhere

void myFunction() {
    int localVar = 50;  // Local scope: only inside myFunction
    cout << globalVar << endl;   // ✅ Can access global
    cout << localVar  << endl;   // ✅ Can access local
}

int main() {
    cout << globalVar << endl;   // ✅ Can access global
    // cout << localVar;         // ❌ ERROR — localVar doesn't exist here
    myFunction();
    return 0;
}
```

### Key Scope Rules

```
┌─────────────────────────────────────────────┐
│  Global Scope (entire file)                 │
│  ┌───────────────┐   ┌───────────────────┐  │
│  │  main()       │   │  myFunction()     │  │
│  │  local vars   │   │  local vars       │  │
│  │  (main only)  │   │  (function only)  │  │
│  └───────────────┘   └───────────────────┘  │
└─────────────────────────────────────────────┘
```

- Variables declared **inside** a function live only for that function call.
- Variables declared **outside** all functions are global.
- Two functions can have variables with the **same name** — they won't conflict.

---

## 8. Function Call Stack

The **call stack** is how your computer keeps track of which function is running and which function called it.

### Example

```cpp
#include <iostream>
using namespace std;

void printCounting(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
    }
}

int main() {
    printCounting(3);
    cout << "Done!" << endl;
    return 0;
}
```

### How the Stack Works

```
Step 1: main() is called
        ┌─────────┐
        │  main() │  ← Stack starts here
        └─────────┘

Step 2: main() calls printCounting(3)
        ┌──────────────────┐
        │  printCounting() │  ← Added on top
        ├──────────────────┤
        │  main()          │
        └──────────────────┘

Step 3: printCounting() finishes → removed from stack
        ┌─────────┐
        │  main() │  ← Control returns here
        └─────────┘

Step 4: main() finishes → stack is empty → program ends
```

> Think of the stack like a stack of books. You add a book (call a function), finish reading it, remove it, and go back to the book below.

---

## 9. Pass by Value

When you pass a variable to a function in C++, a **copy** is made. Changes inside the function do NOT affect the original variable.

```cpp
#include <iostream>
using namespace std;

void dummy(int n) {
    n++;    // Modifies the COPY, not the original
    cout << "Inside dummy, n is " << n << endl;
}

int main() {
    int n;
    cin >> n;           // Say user enters 5
    dummy(n);
    cout << "In main, n is " << n << endl;   // Still 5!
    return 0;
}
```

**Input:** `5`

**Output:**
```
Inside dummy, n is 6
In main, n is 5
```

### Why?

```
main() memory:        dummy() memory:
┌─────────────┐       ┌─────────────────────┐
│  n = 5      │ ──copy──→  │  n = 5 → 6 (copy)   │
└─────────────┘       └─────────────────────┘
   (unchanged)             (discarded after call)
```

Each function call gets its **own separate space in memory**. The function works on a copy, and when the function ends, that copy is destroyed.

> **Pass by Reference** (using `&`) is the opposite — the function works directly on the original. That's a more advanced topic!

---

## 10. Practice Problems

Try writing functions for each of these:

### Beginner
1. Write a function `isEven(int n)` that returns `true` if n is even.
2. Write a function `sum(int a, int b)` that returns the sum.
3. Write a switch statement that prints the day name for numbers 1–7 (1=Monday, 7=Sunday).

### Intermediate
4. Write a function `isPrime(int n)` that returns `true` if n is prime.
5. Write a function `fibonacci(int n)` that prints fibonacci numbers up to n.
6. Write a calculator using a switch statement that keeps running until the user enters 'q'.

### DSA-Level
7. Write a function `nCr(int n, int r)` that uses a `factorial()` helper function.
8. Write a function `countSetBits(int n)` that counts how many 1s are in the binary representation of n.
9. Write a switch-based menu: 1=Find Max, 2=Find Min, 3=Compute Sum, 4=Exit.

---

## Quick Reference Card

```
SWITCH STATEMENT                    FUNCTIONS
─────────────────────────────────   ──────────────────────────────
switch (variable) {                 returnType name(params) {
    case value1:                        // body
        // code                         return value;
        break;                      }
    case value2:
        // code                     Types:
        break;                      - void   → no return
    default:                        - int    → returns int
        // code                     - bool   → returns true/false
}

Rules:                              Scope:
✅ int or char only                 - Local vars live in function
✅ break to stop fall-through       - Global vars live everywhere
❌ no continue inside switch
❌ no variable expressions          Pass by Value:
❌ no float or string               - Function gets a COPY
                                    - Original is NOT changed

Call Stack:
- main() starts first
- Each function call pushes to stack
- Return pops from stack
```

---

*Happy Coding! Functions and switch are the building blocks of clean, efficient C++ — master these and DSA becomes much easier.*
