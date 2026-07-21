# LeetCode 204 - Count Primes

## Problem Statement

Given an integer `n`, return the number of **prime numbers** that are **strictly less than** `n`.

### Examples

#### Example 1

```text
Input: n = 10
Output: 4

Prime Numbers:
2, 3, 5, 7
```

#### Example 2

```text
Input: n = 0
Output: 0
```

#### Example 3

```text
Input: n = 1
Output: 0
```

---

# What is a Prime Number?

A prime number is a number that has exactly **two factors**:

- 1
- Itself

### Examples

```text
2  -> Prime
3  -> Prime
5  -> Prime
7  -> Prime
11 -> Prime
```

### Not Prime

```text
4 = 2 × 2
6 = 2 × 3
8 = 2 × 4
9 = 3 × 3
```

---

# Brute Force Approach

For every number from `2` to `n-1`:

- Check whether it is prime.
- If it is prime, increase the count.

## Complexity

```text
Time  : O(n√n)
Space : O(1)
```

This approach gives **Time Limit Exceeded (TLE)** for large values of `n`.

---

# Optimized Approach (Sieve of Eratosthenes)

Instead of checking every number individually, we assume that every number is prime.

Then we remove all multiples of every prime number.

Finally, the remaining numbers are prime.

---

# Algorithm

### Step 1

Create a boolean array.

```cpp
vector<bool> prime(n, true);
```

Initially every number is considered prime.

---

### Step 2

0 and 1 are not prime.

```cpp
prime[0] = false;
prime[1] = false;
```

---

### Step 3

Start from `2`.

If the current number is prime, mark all its multiples as false.

```cpp
for(int j = i * i; j < n; j += i)
```

---

### Step 4

Count all values that are still `true`.

Those are the prime numbers.

---

# Dry Run

## Input

```text
n = 10
```

Initially

```text
Index : 0 1 2 3 4 5 6 7 8 9

Value : F F T T T T T T T T
```

---

### i = 2

Mark multiples

```text
4 6 8
```

Array

```text
F F T T F T F T F T
```

---

### i = 3

Mark multiples

```text
9
```

Array

```text
F F T T F T F T F F
```

---

Remaining Prime Numbers

```text
2
3
5
7
```

Count = **4**

---

# Why do we start from `i * i`?

Example

```text
i = 5
```

Multiples

```text
5 × 2 = 10
5 × 3 = 15
5 × 4 = 20
```

These numbers have already been marked by `2`, `3`, or `4`.

So we start from

```text
5 × 5 = 25
```

This avoids unnecessary work.

---

# Why do we stop at `i * i < n`?

Suppose

```text
n = 100
```

After checking up to

```text
√100 = 10
```

Every remaining composite number already has a smaller factor.

So checking beyond √n is unnecessary.

---

# Complexity

## Time

```text
O(n log log n)
```

## Space

```text
O(n)
```

---

# C++ Solution

```cpp
class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2)
            return 0;

        vector<bool> prime(n, true);

        prime[0] = false;
        prime[1] = false;

        for(int i = 2; i * i < n; i++) {

            if(prime[i]) {

                for(int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++) {
            if(prime[i])
                count++;
        }

        return count;
    }
};
```

---

# Key Points to Remember

- Prime number has exactly **two factors**.
- `0` and `1` are **not prime**.
- Assume every number is prime initially.
- Mark multiples of every prime as false.
- Start marking from `i * i`.
- Stop the outer loop at `i * i < n`.
- Count all remaining `true` values.

---

# Interview Tip

If an interviewer asks:

> "Can you optimize prime checking for a large range?"

The expected answer is:

> **Use the Sieve of Eratosthenes**, which finds all prime numbers up to `n` in **O(n log log n)** time.