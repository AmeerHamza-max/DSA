# C++ Characters, Arrays & Strings — Complete Guide

## 1. The `char` Type

```cpp
char a = 'z';
```

- `char` is a **single-character** variable type — it holds exactly **one** character in single quotes (`' '`).
- Internally stored as a small integer (1 byte) — the ASCII code of the character.
- Double quotes (`" "`) are for strings, single quotes (`' '`) are for a single `char`.

```cpp
char grade = 'A';
char digit = '9';
char symbol = '$';
```

---

## 2. 1-Dimensional Arrays — Refresher

A normal array stores multiple values of the same type under one name, accessed by index (0-based).

```cpp
int arr[10];
```
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-------|---|---|---|---|---|---|---|---|---|---|
| Value | 7 | 8 | 9 |10 |11 |12 |13 | ? | ? | ? |

A **character array** works the same way, but each box holds one `char`:

```cpp
char ch[10];
```
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|-------|---|---|---|---|---|---|---|
| Value | A | B | C | D | E | F | G |

This is C-style string handling — an array of characters *is* how C (and old-style C++) represents text.

---

## 3. Filling a Char Array

**Traditional (single value) input:**
```cpp
int n;
cin >> n;
```

**Char array filled element-by-element:**
```cpp
char ch[20];
for (int i = 0; i < 20; i++) {
    cin >> ch[i];
}
```

### The Null Character (`'\0'`)
- If you declare `char ch[20]` but only fill 10 boxes with real characters, the compiler/runtime fills (or expects) the **remaining boxes with the null character `'\0'`**.
- `'\0'` is the **string terminator** in C-style strings — it marks "the string ends here."

### Why This Matters
- When a C-style string is printed (e.g., with `cout` or `printf`), the compiler **reads characters one by one until it hits `'\0'`**, then it **stops** — even if more characters exist in the array after it.
- **Example:**
```cpp
char name[10] = {'A', 'l', 'i', '\0', 'K', 'h', 'a', 'n'};
cout << name;   // Output: Ali   (stops at the null character)
```
Even though `'K', 'h', 'a', 'n'` exist in memory, they are never printed because the null character before them tells the program "the string is over."

### Whitespace Behavior with `cin >>`
- `cin >> ch` (reading into a char array) **stops reading at the first space, tab, or Enter (newline)**.
- It automatically places a `'\0'` right after the last character read.
- So if you type `John Smith`, `cin >> ch` only captures `John` — the space ends the input, and the null terminator is inserted right after `n`.

```cpp
char name[20];
cin >> name;
// Input: John Smith
// name = "John" (stops at the space, "Smith" is left in the input buffer)
```

---

## 4. Reading Full Lines: `cin.getline()`

Since `cin >>` stops at whitespace, use `cin.getline()` to read an entire line **including spaces**, until Enter is pressed.

```cpp
char str[100];
cin.getline(str, 100);   // reads up to 99 chars, then adds '\0'
```

**Syntax:**
```cpp
cin.getline(char_array, size);
```
- `char_array` → the destination array
- `size` → maximum number of characters to read (including the null terminator)
- Stops early if it encounters `'\n'` (Enter key)

```cpp
char fullName[50];
cout << "Enter full name: ";
cin.getline(fullName, 50);
cout << "Hello, " << fullName;
// Input: John Smith
// Output: Hello, John Smith
```

---

## 5. `string` in C++ (The `std::string` Class)

```cpp
#include <string>
using namespace std;

string s;
```

- `string` is a **built-in class** (not a raw array) from the C++ Standard Library.
- Much more powerful and safer than char arrays — no fixed size, no manual null-terminator management, supports operators like `+`, `==`, `<`, etc.

### Internal Storage
> A `string` stores its data internally as a **null-terminated C-string**, but in normal usage it does **not allow direct access to that null terminator** — you don't have to think about `'\0'` at all when using `string`.

```cpp
string s = "Hello";
cout << s.length();  // 5 — length does NOT include the hidden '\0'
```

### Common `string` Member Functions

```cpp
string str = "Hello";

str.push_back('!');   // adds a character at the end   -> "Hello!"
str.pop_back();        // removes the last character    -> "Hello"

str.length();           // returns number of characters -> 5
str.size();              // same as length()             -> 5

str += " World";        // concatenation                -> "Hello World"
str[0];                    // access like an array          -> 'H'
```

### Length of a String
```cpp
string s = "Programming";
cout << s.length();   // 11
// or
cout << s.size();     // 11 (identical to length())
```
For a C-style char array, length is found differently — using `strlen()` from `<cstring>`:
```cpp
#include <cstring>
char arr[] = "Programming";
cout << strlen(arr);   // 11
```

---

## 6. Key Differences: Char Array vs `string`

| Feature | `char` Array (C-style) | `string` (C++ class) |
|---|---|---|
| Type | Raw array of `char` | Class object |
| Size | Fixed at declaration | Dynamic — grows/shrinks automatically |
| Termination | Manually relies on `'\0'` | Handled internally, hidden from user |
| Header needed | None (built-in) | `#include <string>` |
| Reading with spaces | `cin.getline(arr, size)` | `getline(cin, s)` |
| Reading without spaces | `cin >> arr` | `cin >> s` |
| Concatenation | `strcat()` (manual, unsafe) | `+` or `+=` (built-in, safe) |
| Length | `strlen(arr)` | `s.length()` or `s.size()` |
| Modify (add/remove char) | Manual index manipulation | `push_back()`, `pop_back()` |
| Safety | Prone to overflow/errors | Safer, automatically managed |
| Comparison | `strcmp()` | `==`, `<`, `>` operators directly |

### Reading a Full Line into a `string`
```cpp
string name;
cout << "Enter full name: ";
getline(cin, name);       // note: getline(cin, s) — NOT s.getline()
cout << "Hi, " << name;
```

---

## 7. Complete `string` Member Function Reference

```cpp
string s = "Programming";
```

### Size / Capacity
```cpp
s.length();          // number of characters -> 11
s.size();             // same as length()      -> 11
s.empty();            // true if s == ""       -> false
s.capacity();        // current allocated storage size
s.reserve(100);      // pre-allocate space for 100 chars (performance)
s.resize(5);          // truncates/pads s to exactly 5 chars -> "Progr"
s.shrink_to_fit();  // reduce capacity to fit size
```

### Access
```cpp
s[0];              // 'P'  (no bounds checking)
s.at(0);           // 'P'  (throws exception if out of range - safer)
s.front();        // first character -> 'P'
s.back();         // last character  -> 'g'
```

### Modifying
```cpp
s.push_back('!');            // add char at end
s.pop_back();                 // remove last char
s.append(" Language");      // add a string at the end
s.insert(3, "XYZ");           // insert "XYZ" at index 3
s.erase(2, 4);                  // erase 4 chars starting at index 2
s.replace(0, 4, "Code");     // replace first 4 chars with "Code"
s.clear();                      // empty the string completely
swap(s1, s2);                   // swap contents of two strings
```

### Searching
```cpp
s.find("gram");         // index of first occurrence, or string::npos if not found
s.rfind("m");             // index of LAST occurrence
s.find_first_of("aeiou"); // index of first vowel found
s.find_last_of("aeiou");  // index of last vowel found

if (s.find("gram") != string::npos) {
    cout << "Found!";
}
```

### Substrings & Comparison
```cpp
s.substr(3);            // substring from index 3 to end
s.substr(3, 4);          // substring: 4 chars starting at index 3
s.compare("Programming"); // 0 if equal, <0 or >0 otherwise
s == "Programming";       // simpler equality check (preferred)
```

### Conversion to C-style String
```cpp
const char* p = s.c_str();  // read-only C-string (null-terminated) — used when a function needs char*
const char* d = s.data();   // similar to c_str()
```

### Iterating a String
```cpp
// index-based
for (int i = 0; i < s.length(); i++) cout << s[i];

// range-based (cleanest)
for (char c : s) cout << c;

// iterators
for (string::iterator it = s.begin(); it != s.end(); it++) cout << *it;
```

---

## 8. C-String Functions (for `char` Arrays) — `<cstring>`

Since `char` arrays don't have member functions, C provides free functions:

```cpp
#include <cstring>

char a[20] = "Hello";
char b[20] = "World";

strlen(a);           // length -> 5 (does not count '\0')
strcpy(a, b);         // copies b into a  -> a becomes "World"
strncpy(a, b, 3);    // copies only first 3 chars (safer, bounded)
strcat(a, b);         // concatenates b onto end of a
strncat(a, b, 3);    // concatenates only first 3 chars of b (safer)
strcmp(a, b);         // 0 if equal, <0 if a<b, >0 if a>b (alphabetical)
strncmp(a, b, 3);    // compares only first 3 chars
strchr(a, 'l');        // pointer to first occurrence of 'l' in a
strstr(a, "World");  // pointer to first occurrence of substring
```

> **Note:** `strcpy`/`strcat` don't check array bounds — a common source of buffer overflow bugs. Prefer `string` when possible; use the `n`-prefixed versions (`strncpy`, `strncat`) when you must use char arrays.

---

## 9. Character Classification & Conversion — `<cctype>`

Useful when processing individual characters (from either a `char` array or a `string`):

```cpp
#include <cctype>

isalpha('a');   // true if letter
isdigit('5');   // true if digit 0-9
isalnum('a');   // true if letter or digit
isspace(' ');   // true if space/tab/newline
isupper('A');   // true if uppercase
islower('a');   // true if lowercase
ispunct('!');   // true if punctuation

toupper('a');   // 'A'
tolower('A');   // 'a'
```

```cpp
// Example: convert a whole string to uppercase
string s = "hello";
for (int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);
}
cout << s;  // HELLO
```

---

## 10. String ↔ Number Conversions

```cpp
#include <string>

// number to string
string s1 = to_string(123);      // "123"
string s2 = to_string(3.14);     // "3.140000"

// string to number
int n     = stoi("123");          // 123
long l    = stol("123456");       // long
float f    = stof("3.14");         // 3.14f
double d = stod("3.14159");     // 3.14159
```

---

## 11. Common Pitfalls & Extra Notes

- **`==` on char arrays compares memory addresses, not content.** Use `strcmp(a, b) == 0` instead.
  ```cpp
  char a[] = "hi", b[] = "hi";
  a == b;          // false! (compares pointers)
  strcmp(a,b)==0;  // true (compares content)
  ```
- **`string` supports `==` directly** and compares actual content — no `strcmp` needed.
- **Buffer overflow risk:** writing more characters into a `char` array than its declared size corrupts adjacent memory. `string` grows automatically and avoids this.
- **`string::npos`** is a special constant (usually `-1` as `size_t`) returned by `find()` when nothing is found — always check against it, never against `-1` directly.
- **Mixing `cin >>` and `getline`:** after `cin >> n`, a leftover `'\n'` sits in the input buffer. Calling `getline()` right after will read that empty leftover line. Fix with `cin.ignore();` before the `getline()` call.
  ```cpp
  int age; string name;
  cin >> age;
  cin.ignore();          // clears leftover newline
  getline(cin, name);
  ```
- **Strings are mutable** — you can change individual characters (`s[0] = 'X';`) unlike string literals in some other languages.
- **Concatenating with `+`** requires at least one operand to be a `string` object: `"abc" + "def"` (two literals) is invalid, but `string("abc") + "def"` works.

---

## 12. Quick Summary

- `char` → holds **one** character.
- `char arr[n]` → a fixed-size C-style string; **must** be null-terminated (`'\0'`) to print correctly; unused/extra positions after `'\0'` are ignored on output.
- `cin >>` stops at whitespace (space/tab/enter) for both char arrays and `string`.
- `cin.getline(arr, size)` reads a full line into a char array; `getline(cin, s)` does the same for a `string`.
- `string` is the modern, safe, dynamic alternative to char arrays — internally null-terminated but you never manage that yourself.
- Core `string` methods: `length()/size()`, `push_back()/pop_back()`, `substr()`, `find()`, `insert()`, `erase()`, `replace()`, `append()`, `c_str()`.
- Core C-string functions (`<cstring>`): `strlen()`, `strcpy()`, `strcat()`, `strcmp()`.
- Use `<cctype>` (`isalpha`, `toupper`, etc.) for per-character checks/conversions.
- Use `to_string()` / `stoi()` family for number ↔ string conversion.
- Always compare char arrays with `strcmp()`, never `==`; always check `string::npos`, never `-1`.
