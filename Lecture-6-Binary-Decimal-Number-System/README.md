# 🔢 Binary & Decimal Conversion — Complete Guide

> **For absolute beginners** — No prior knowledge needed. By the end of this guide, you'll fully understand how computers count and how to convert between number systems — both in theory and in code.

---

## 📚 Table of Contents

1. [What Are Number Systems?](#1-what-are-number-systems)
2. [The Decimal System (Base-10)](#2-the-decimal-system-base-10)
3. [The Binary System (Base-2)](#3-the-binary-system-base-2)
4. [Why Do Computers Use Binary?](#4-why-do-computers-use-binary)
5. [Decimal → Binary Conversion](#5-decimal--binary-conversion)
6. [Binary → Decimal Conversion](#6-binary--decimal-conversion)
7. [Bit Manipulation Shortcuts](#7-bit-manipulation-shortcuts)
8. [Code Implementations](#8-code-implementations)
9. [Common Mistakes](#9-common-mistakes)
10. [Quick Reference Table](#10-quick-reference-table)
11. [Practice Problems](#11-practice-problems)

---

## 1. What Are Number Systems?

A **number system** is simply a way to represent quantities using symbols (digits).

Think of it like a language — different languages use different symbols to express the same idea.

| System    | Base | Digits Used         | Used By        |
|-----------|------|---------------------|----------------|
| Decimal   | 10   | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 | Humans |
| Binary    | 2    | 0, 1                | Computers      |
| Octal     | 8    | 0–7                 | Some OS tools  |
| Hexadecimal | 16 | 0–9, A–F            | Memory/color codes |

> **Real-world analogy:** Imagine you only have two light switches (ON and OFF). That's exactly how computers "think" — everything is either ON (1) or OFF (0). That's binary!

---

## 2. The Decimal System (Base-10)

You've used this your entire life. It has **10 digits**: `0 1 2 3 4 5 6 7 8 9`

The key insight: each **position** represents a **power of 10**.

### How Positional Value Works

```
Number:   5  3  7
          |  |  |
          |  |  └──  7 × 10⁰ = 7 × 1    =   7
          |  └─────  3 × 10¹ = 3 × 10   =  30
          └────────  5 × 10² = 5 × 100  = 500
                                           ───
                                           537  ✓
```

**Rule:** As you move left, multiply by 10 each time.

---

## 3. The Binary System (Base-2)

Binary has only **2 digits**: `0` and `1`

Each digit in binary is called a **bit** (Binary digIT).

The key insight: each **position** represents a **power of 2**.

### How Positional Value Works

```
Binary:   1  0  1  0
          |  |  |  |
          |  |  |  └──  0 × 2⁰ = 0 × 1  =  0
          |  |  └─────  1 × 2¹ = 1 × 2  =  2
          |  └────────  0 × 2² = 0 × 4  =  0
          └───────────  1 × 2³ = 1 × 8  =  8
                                           ──
                                           10  ✓
```

So binary `1010` = decimal `10`. Makes sense!

### Powers of 2 (Memorize These!)

| Power | Value |
|-------|-------|
| 2⁰    | 1     |
| 2¹    | 2     |
| 2²    | 4     |
| 2³    | 8     |
| 2⁴    | 16    |
| 2⁵    | 32    |
| 2⁶    | 64    |
| 2⁷    | 128   |
| 2⁸    | 256   |
| 2⁹    | 512   |
| 2¹⁰   | 1024  |

> **Memory trick:** Each power of 2 is exactly double the previous one: 1, 2, 4, 8, 16, 32, 64...

---

## 4. Why Do Computers Use Binary?

Computers are built from billions of tiny electronic switches called **transistors**.

- A transistor can be either **ON** or **OFF**
- ON = `1`, OFF = `0`
- This is naturally **binary**

### The Engineering Reason

| Voltage Level | Meaning |
|---------------|---------|
| High (~5V or 3.3V) | 1 (true) |
| Low (~0V)          | 0 (false) |

It's much easier and more reliable to distinguish between two states (high/low) than ten states (like decimal requires). Binary gives computers their **speed** and **reliability**.

> **Analogy:** Imagine trying to communicate with someone far away using 10 different flag positions versus just 2 (flag up = 1, flag down = 0). Two states are much easier to distinguish reliably!

---

## 5. Decimal → Binary Conversion

### The Division Method (Divide by 2)

**Algorithm:**
1. Divide the number by 2
2. Write down the **remainder** (0 or 1)
3. Use the **quotient** as the new number
4. Repeat until quotient = 0
5. **Read remainders from bottom to top**

### Example 1: Convert 5 to Binary

```
Step | Number | ÷ 2 | Quotient | Remainder
-----|--------|-----|----------|----------
  1  |   5    |  2  |    2     |    1      ← last bit (LSB)
  2  |   2    |  2  |    1     |    0
  3  |   1    |  2  |    0     |    1      ← first bit (MSB)

Read remainders bottom to top: 1 0 1

5 (decimal) = 101 (binary)  ✓
```

**Verify:** 1×2² + 0×2¹ + 1×2⁰ = 4 + 0 + 1 = 5 ✓

---

### Example 2: Convert 10 to Binary

```
Step | Number | ÷ 2 | Quotient | Remainder
-----|--------|-----|----------|----------
  1  |  10    |  2  |    5     |    0      ← last bit (LSB)
  2  |   5    |  2  |    2     |    1
  3  |   2    |  2  |    1     |    0
  4  |   1    |  2  |    0     |    1      ← first bit (MSB)

Read remainders bottom to top: 1 0 1 0

10 (decimal) = 1010 (binary)  ✓
```

**Verify:** 1×2³ + 0×2² + 1×2¹ + 0×2⁰ = 8 + 0 + 2 + 0 = 10 ✓

---

### Example 3: Convert 8 to Binary

```
Step | Number | ÷ 2 | Quotient | Remainder
-----|--------|-----|----------|----------
  1  |   8    |  2  |    4     |    0
  2  |   4    |  2  |    2     |    0
  3  |   2    |  2  |    1     |    0
  4  |   1    |  2  |    0     |    1

Read remainders bottom to top: 1 0 0 0

8 (decimal) = 1000 (binary)  ✓
```

> **Notice:** 8 is a power of 2 (2³), so its binary form is 1 followed by three 0s. All powers of 2 follow this pattern!

---

### Visual Flowchart

```
Start with N
     │
     ▼
┌─────────────┐
│  N != 0 ?   │──── No ──→ Stop, read remainders bottom-to-top
└─────────────┘
     │ Yes
     ▼
┌─────────────────┐
│ remainder = N%2 │  (0 or 1)
│ Write it down   │
└─────────────────┘
     │
     ▼
┌─────────────┐
│   N = N/2   │  (integer division)
└─────────────┘
     │
     └──────────── Loop back up ↑
```

---

## 6. Binary → Decimal Conversion

### The Positional Method (Multiply by Powers of 2)

**Algorithm:**
1. Write out the binary number
2. Assign powers of 2 from **right to left** (starting at 2⁰)
3. Multiply each bit by its power of 2
4. Sum all the results

### Example 1: Convert `101` to Decimal

```
Binary:    1    0    1
           │    │    │
Powers:   2²   2¹   2⁰
           │    │    │
Values:    4    2    1
           │    │    │
Product:  1×4  0×2  1×1
           │    │    │
Results:   4  + 0  + 1  = 5

101 (binary) = 5 (decimal)  ✓
```

---

### Example 2: Convert `1010` to Decimal

```
Binary:    1    0    1    0
           │    │    │    │
Powers:   2³   2²   2¹   2⁰
           │    │    │    │
Values:    8    4    2    1
           │    │    │    │
Product:  1×8  0×4  1×2  0×1
           │    │    │    │
Results:   8  + 0  + 2  + 0  = 10

1010 (binary) = 10 (decimal)  ✓
```

---

### Example 3: Convert `11001` to Decimal

```
Binary:    1    1    0    0    1
           │    │    │    │    │
Powers:   2⁴   2³   2²   2¹   2⁰
           │    │    │    │    │
Values:   16    8    4    2    1
           │    │    │    │    │
Product: 1×16 1×8  0×4  0×2  1×1
           │    │    │    │    │
Results:  16  + 8  + 0  + 0  + 1  = 25

11001 (binary) = 25 (decimal)  ✓
```

> **Quick tip:** You only need to add the powers where the bit is `1`. Ignore all `0` positions — they contribute nothing.

---

## 7. Bit Manipulation Shortcuts

These are tricks programmers use to work with binary faster, without manual division.

### Getting the Last Bit (Least Significant Bit)

```
Use: n & 1

If n = 10 (binary: 1010)
   1010
&  0001
= ─────
   0000  → last bit is 0 (even number!)

If n = 5 (binary: 101)
   101
&  001
= ────
   001  → last bit is 1 (odd number!)
```

> **Real use:** `n & 1` tells you if a number is **odd (1)** or **even (0)**. Much faster than `n % 2`!

---

### Shifting Right (n >> 1)

```
n >> 1 is the same as n / 2 (integer division)

n = 10 → binary: 1010
         shift right by 1
         → 0101 = 5

This "removes" the rightmost bit and shifts everything right.
```

### Why Use Bit Operations?

| Operation    | Math equivalent | Speed    |
|--------------|-----------------|----------|
| `n & 1`      | `n % 2`         | Faster   |
| `n >> 1`     | `n / 2`         | Faster   |
| `n << 1`     | `n * 2`         | Faster   |

Bit operations work directly on the CPU's hardware — no division circuits needed.

---

## 8. Code Implementations

### C++ — Decimal to Binary

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;

    while (n != 0) {
        int bit = n & 1;          // Get the last bit (0 or 1)
        ans = (bit * pow(10, i)) + ans;  // Place it in correct position
        n = n >> 1;               // Shift right (same as n = n / 2)
        i++;                      // Move to next position
    }

    cout << "Binary: " << ans << endl;
    return 0;
}

/*
  Example: n = 5 (binary: 101)

  Iteration 1: bit = 5&1 = 1, ans = 1*10^0 + 0 = 1,   n = 5>>1 = 2, i=1
  Iteration 2: bit = 2&1 = 0, ans = 0*10^1 + 1 = 1,   n = 2>>1 = 1, i=2
  Iteration 3: bit = 1&1 = 1, ans = 1*10^2 + 1 = 101, n = 1>>1 = 0, i=3
  Loop ends.

  Output: 101  ✓
*/
```

---

### C++ — Binary to Decimal

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;      // User enters binary number as integer e.g. 101

    int ans = 0;
    int i = 0;

    while (n != 0) {
        int digit = n % 10;        // Get the rightmost digit (0 or 1)

        if (digit == 1) {
            ans = ans + pow(2, i); // If bit is 1, add 2^i to answer
        }

        n = n / 10;                // Remove the rightmost digit
        i++;                       // Move to next power of 2
    }

    cout << "Decimal: " << ans << endl;
    return 0;
}

/*
  Example: n = 1010 (binary for 10)

  Iteration 1: digit = 1010%10 = 0, skip (digit!=1), n=101, i=1
  Iteration 2: digit = 101%10  = 1, ans = 0+2^1 = 2,   n=10,  i=2
  Iteration 3: digit = 10%10   = 0, skip,                n=1,   i=3
  Iteration 4: digit = 1%10    = 1, ans = 2+2^3 = 10,  n=0,   i=4
  Loop ends.

  Output: 10  ✓
*/
```

---

### JavaScript — Both Conversions

```javascript
// Decimal → Binary
function decimalToBinary(n) {
    if (n === 0) return "0";

    let result = "";

    while (n !== 0) {
        let bit = n & 1;        // Get last bit
        result = bit + result;  // Prepend to string (builds right-to-left)
        n = n >> 1;             // Shift right
    }

    return result;
}

// Binary → Decimal
function binaryToDecimal(binaryStr) {
    let decimal = 0;
    let power = 0;

    // Process from right to left
    for (let i = binaryStr.length - 1; i >= 0; i--) {
        let bit = parseInt(binaryStr[i]);

        if (bit === 1) {
            decimal += Math.pow(2, power); // Add 2^power if bit is 1
        }

        power++;
    }

    return decimal;
}

// Test
console.log(decimalToBinary(5));    // "101"
console.log(decimalToBinary(10));   // "1010"
console.log(decimalToBinary(8));    // "1000"

console.log(binaryToDecimal("101"));   // 5
console.log(binaryToDecimal("1010"));  // 10
console.log(binaryToDecimal("1000"));  // 8
```

---

### Python — One-Liners (for reference)

```python
# Python built-ins (great for quick checks)
bin(10)        # '0b1010' → binary of 10
int('1010', 2) # 10       → binary string to decimal

# Verify your manual answers against these!
print(bin(5))       # '0b101'
print(bin(8))       # '0b1000'
print(int('101', 2))  # 5
```

---

## 9. Common Mistakes

### ❌ Mistake 1: Forgetting to Read Remainders in Reverse

```
Wrong order: 5 → remainders: 1, 0, 1 → reading as 101 (correct here by luck)
             but 10 → remainders: 0, 1, 0, 1 → WRONG if read as 0101

✅ Always read from LAST remainder to FIRST (bottom to top)
```

### ❌ Mistake 2: Using Float Powers with Integer Logic

```cpp
// ❌ BUGGY — pow() returns a float, can cause rounding errors
ans = ans + pow(2, i);  // pow(2,3) might return 7.9999 → int becomes 7!

// ✅ SAFE — Use integer left shift instead
ans = ans + (1 << i);   // 1 << 3 = 8 exactly, always
```

### ❌ Mistake 3: Not Handling Edge Case n = 0

```javascript
// ❌ This loop never runs for n = 0
while (n !== 0) { ... }
// Output: empty / undefined

// ✅ Always handle 0 separately
if (n === 0) return "0";
```

### ❌ Mistake 4: Confusing Binary Input as a String vs Integer

```
Binary "1010" as a string → process character by character
Binary 1010 as an integer → extract digits using % 10

Both work, but don't mix them up in your code!
```

---

## 10. Quick Reference Table

| Decimal | Binary | Hex  |
|---------|--------|------|
| 0       | 0000   | 0    |
| 1       | 0001   | 1    |
| 2       | 0010   | 2    |
| 3       | 0011   | 3    |
| 4       | 0100   | 4    |
| 5       | 0101   | 5    |
| 6       | 0110   | 6    |
| 7       | 0111   | 7    |
| 8       | 1000   | 8    |
| 9       | 1001   | 9    |
| 10      | 1010   | A    |
| 11      | 1011   | B    |
| 12      | 1100   | C    |
| 13      | 1101   | D    |
| 14      | 1110   | E    |
| 15      | 1111   | F    |
| 16      | 10000  | 10   |
| 32      | 100000 | 20   |
| 64      | 1000000| 40   |
| 128     | 10000000| 80  |
| 255     | 11111111| FF  |

> **Note:** 255 in binary is `11111111` — eight 1s. This is the maximum value of one byte (8 bits). That's why IP addresses go from 0–255!

---

## 11. Practice Problems

Try these without code first — just pen and paper!

### Beginner

1. Convert `13` to binary
2. Convert `1101` to decimal
3. Convert `0` to binary (edge case!)

### Intermediate

4. Convert `255` to binary — what do you notice?
5. Convert `11111111` to decimal
6. What decimal number has binary `10000`?

### Advanced

7. Without converting, is `10110` odd or even? How do you know?
8. What is `1010 >> 1` in decimal?
9. Add `101 + 011` in binary (binary addition)

### Answers

<details>
<summary>Click to reveal answers</summary>

1. `13` → `1101`
2. `1101` → 13
3. `0` → `0` (special case)
4. `255` → `11111111` (all 8 bits are 1 — maximum 1-byte value)
5. `11111111` → 255
6. `10000` → 16 (= 2⁴)
7. `10110` is **even** — the last bit is 0
8. `1010 >> 1` = `0101` = 5 (which is 10 ÷ 2)
9. `101 + 011` = `1000` (= 5 + 3 = 8 ✓)

</details>

---

## 🎯 Key Takeaways

| Concept | Rule |
|--------|------|
| Decimal to Binary | Divide by 2, collect remainders, read bottom-to-top |
| Binary to Decimal | Multiply each bit by 2^position, sum them |
| Last bit | Use `n & 1` — gives 0 (even) or 1 (odd) |
| Shift right | `n >> 1` = `n / 2` (fast!) |
| Shift left | `n << 1` = `n * 2` (fast!) |
| 1-byte max | `11111111` = 255 |

---

## 🌍 Real-World Usage

- **IP Addresses** — `192.168.1.1` is four 8-bit binary numbers
- **File Permissions** in Linux — `chmod 755` uses octal (related to binary)
- **Colors in CSS** — `#FF5733` is three hex values (each is 8 bits of binary)
- **Image pixels** — Each RGB channel is 0–255 (8 bits = 1 byte)
- **Encryption** — XOR operations on bits protect your passwords
- **Computer memory** — RAM, hard drives store everything as binary

---

*Happy coding! Remember: every complex program ever written is ultimately just 0s and 1s. Now you understand the foundation.*