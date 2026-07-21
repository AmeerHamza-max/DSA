# Math for DSA — Core Concepts

A working reference for the math you'll reuse across competitive programming and interview problems: fast exponentiation, GCD/HCF, modular arithmetic, primality testing, and sieves. Each section has the concept, the why, the C++ template, and complexity.

---

## 1. Fast Exponentiation (Binary Exponentiation)

### Why it matters
Computing `a^b` by multiplying `a` by itself `b` times is O(b). For `b` up to 10^9 or 10^18 (common in problems), that's too slow. Binary exponentiation gets it down to **O(log b)**.

### The idea
Any exponent `b` can be written in binary. Example: `11 = 1011₂ = 8 + 2 + 1`.

So `a^11 = a^8 * a^2 * a^1`.

Each of those powers (`a^1, a^2, a^4, a^8, ...`) is just the previous one **squared**. So instead of 11 multiplications, you do about `log2(11) ≈ 4` squarings, and multiply in the ones where the bit is set.

Walkthrough for `a^11`:
```
n = 11 = 1011 (binary)
bit 1 (LSB=1): res = res * a         -> a^1
a = a*a                              -> a^2
bit 1 (=1)   : res = res * a         -> a^1 * a^2 = a^3
a = a*a                              -> a^4
bit 0        : skip
a = a*a                              -> a^8
bit 1 (=1)   : res = res * a         -> a^3 * a^8 = a^11
```

### Your code, fixed
Your version had two bugs: `a` was never declared/initialized, and the function never returned or printed `res`.

```cpp
#include <iostream>
using namespace std;

long long power(long long a, long long n, long long mod = 0) {
    long long res = 1;
    a = a % (mod ? mod : LLONG_MAX); // optional: keep numbers small if mod is used
    while (n > 0) {
        if (n & 1) {          // if current bit is 1
            res = res * a;
            if (mod) res %= mod;
        }
        a = a * a;             // square the base
        if (mod) a %= mod;
        n = n >> 1;             // move to next bit
    }
    return res;
}

int main() {
    long long a, n;
    cout << "Enter base a and exponent n = ";
    cin >> a >> n;
    cout << power(a, n) << endl;
}
```

### Complexity
- Time: **O(log n)**
- Space: **O(1)** (iterative version)

### Where it shows up
- Computing `a^b mod m` for huge exponents (modular exponentiation — same pattern, just mod after each multiplication)
- Matrix exponentiation (Fibonacci in O(log n), linear recurrences)
- Modular inverse via Fermat's Little Theorem: `a^(m-2) mod m` when `m` is prime

---

## 2. GCD / HCF (Greatest Common Divisor)

### Why it matters
GCD shows up constantly: simplifying fractions, LCM (`lcm(a,b) = a*b/gcd(a,b)`), checking coprimality, modular inverse, and number-theory problems in general.

### The idea (Euclidean Algorithm)
The key identity: `gcd(a, b) = gcd(b, a % b)`, with `gcd(a, 0) = a`.

Why subtraction works but is slow: `gcd(a, b) = gcd(a - b, b)` when `a > b` is true, but if `a` is much bigger than `b` (e.g. `gcd(1000000, 1)`), you'd subtract a million times. Using `%` instead of repeated subtraction jumps straight to the same result in one step — that's the whole optimization.

### Your code, fixed
Your version has two bugs: `b - a` doesn't actually assign anything (should be `b = b - a`), and it uses slow subtraction instead of `%`. Also, the `if(a==0)` / `if(b==0)` checks before the loop are redundant once you use the `%` version, since `gcd(a,b) = gcd(b, a%b)` naturally hits base case `b==0`.

**Subtraction-based (your original idea, corrected):**
```cpp
int gcd(int a, int b) {
    while (a != b) {
        if (a > b) a = a - b;
        else       b = b - a;   // was `b-a;` — missing assignment
    }
    return a;
}
```

**Euclidean, using `%` (preferred — much faster):**
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(a % b, b % a == a ? b : b); // simpler below
}

// cleaner standard form:
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

C++17+ also has `std::__gcd(a, b)` and C++17's `<numeric>` header has `std::gcd(a, b)` built in — use those in contests to save time.

### Complexity
- Subtraction method: O(max(a,b)) worst case — slow
- Euclidean (`%`) method: **O(log(min(a,b)))** — this is the one to actually use

### LCM
```cpp
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;   // divide first to avoid overflow
}
```

---

## 3. Modular Arithmetic

### Why it matters
Answers in DSA problems are often asked "mod 10^9 + 7" because the real answer overflows even 64-bit integers (think: counting paths, combinatorics, big products). You need to know which operations distribute cleanly over `%` and which don't.

### The identities

| Operation | Rule |
|---|---|
| Addition | `(a + b) % m = ((a % m) + (b % m)) % m` |
| Subtraction | `(a - b) % m = ((a % m) - (b % m) + m) % m`  (the `+ m` avoids negative results) |
| Multiplication | `(a * b) % m = ((a % m) * (b % m)) % m` |
| Division | **Does not distribute directly.** You need the **modular inverse**: `(a / b) % m = (a * inverse(b)) % m` |

### Modular inverse
Only well-defined when `gcd(b, m) = 1` (b and m are coprime). Two common ways to find it:
1. **If `m` is prime** (most common in contests, e.g. `10^9+7`): use Fermat's Little Theorem — `inverse(b) = b^(m-2) mod m`, computed with fast exponentiation from section 1.
2. **General case**: Extended Euclidean Algorithm.

```cpp
long long modInverse(long long b, long long m) {
    return power(b, m - 2, m);   // only valid when m is prime
}
```

### Common pitfall
Always take `% m` immediately after every multiplication in a loop — not just at the end — or you'll overflow `long long` before the mod ever gets applied. This is the #1 bug source in modular arithmetic problems.

---

## 4. Prime Numbers

### Checking if a single number is prime
Naive approach checks divisors up to `n`, but you only need to check up to `√n` — if `n = a * b` and both `a, b > √n`, then `a * b > n`, contradiction. So one of them must be ≤ `√n`.

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; (long long)i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

**Complexity:** O(√n) per check.

Use this when you need to check **one or a few** numbers. For checking many numbers up to some limit `N`, use a sieve instead (much faster overall).

---

## 5. Sieve of Eratosthenes

### Why it matters
If you need to know which numbers in `[1, N]` are prime — not just one number — checking each individually with `isPrime()` costs `O(N√N)`. The sieve does it in **O(N log log N)**, essentially linear.

### The idea
Start assuming everything is prime. Starting from 2, cross out every multiple of 2 (they can't be prime). Move to the next unmarked number (3), cross out its multiples. Repeat. Whatever survives is prime.

```cpp
#include <vector>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; (long long)i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {   // start at i*i, not 2*i — smaller multiples already marked
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
```

**Why start marking from `i*i`:** any smaller multiple of `i` (like `2i, 3i, ... (i-1)*i`) already got marked by a smaller prime factor earlier in the loop.

### Complexity
- Time: **O(N log log N)**
- Space: **O(N)**

### Use case
Precompute primality for all numbers up to `10^6` or `10^7` once, then answer many queries in O(1).

---

## 6. Segmented Sieve

### Why it matters
The regular sieve needs an array of size `N`. If you need primes in a range like `[L, R]` where `R` can be up to `10^12` but `R - L` is small (say ≤ 10^6), you can't allocate an array of size `10^12`. Segmented sieve solves this.

### The idea
1. Any composite number `x` in `[L, R]` must have a prime factor `≤ √R`.
2. So first sieve all primes up to `√R` normally (small array).
3. Then, for the range `[L, R]`, use only those small primes to mark composites — allocate an array only of size `R - L + 1`.

```cpp
#include <vector>
#include <cmath>
using namespace std;

vector<bool> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R) + 1;
    vector<bool> baseIsPrime = sieve(limit);   // primes up to sqrt(R)
    vector<long long> basePrimes;
    for (long long i = 2; i <= limit; i++)
        if (baseIsPrime[i]) basePrimes.push_back(i);

    vector<bool> segment(R - L + 1, true);
    if (L == 1) segment[0] = false;   // 1 is not prime

    for (long long p : basePrimes) {
        // find first multiple of p that is >= L
        long long start = max(p * p, ((L + p - 1) / p) * p);
        for (long long j = start; j <= R; j += p) {
            segment[j - L] = false;
        }
    }
    return segment;   // segment[i] corresponds to number (L + i)
}
```

### Complexity
- Time: **O((R - L + 1) log log R + √R log log √R)**
- Space: **O((R - L) + √R)** — this is the whole point, it's independent of `R` on its own

---

## 7. Combinatorics (nCr, nPr)

### Why it matters
"How many ways to..." questions are everywhere: choosing subsets, arranging items, counting paths on a grid. You need factorials, `nCr`, and how to compute them fast under a mod.

### The formulas
- Permutations: `nPr = n! / (n-r)!` — order matters
- Combinations: `nCr = n! / (r! * (n-r)!)` — order doesn't matter
- Pascal's identity: `nCr = (n-1)C(r-1) + (n-1)Cr` — basis for DP table construction

### Computing nCr mod p (the standard contest pattern)
Precompute factorials once, then answer each query in O(log p) using the modular inverse from section 3.

```cpp
const int MOD = 1e9 + 7;
const int MAXN = 200005;
long long fact[MAXN], invFact[MAXN];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    invFact[MAXN-1] = power(fact[MAXN-1], MOD - 2, MOD);   // Fermat's little theorem
    for (int i = MAXN - 2; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}
```

### Complexity
- Precompute: O(MAXN)
- Each query: O(1) after precompute

### Where it shows up
- Counting paths on a grid, subsets, arrangements
- Probability problems phrased as counting
- Combined with DP (e.g. "number of ways" DP that reduces to a closed-form nCr)

---

## 8. Bit Manipulation

### Why it matters
Bitwise tricks turn O(n) or O(2^n) brute-force checks into O(1) or O(log n) operations, and subset/state-compression DP relies entirely on this.

### Core operations

| Task | Code |
|---|---|
| Check if bit `i` is set | `(n >> i) & 1` |
| Set bit `i` | `n \| (1 << i)` |
| Clear bit `i` | `n & ~(1 << i)` |
| Toggle bit `i` | `n ^ (1 << i)` |
| Check power of 2 | `n && !(n & (n-1))` |
| Count set bits | `__builtin_popcount(n)` |
| Turn off lowest set bit | `n & (n-1)` |
| Isolate lowest set bit | `n & (-n)` |
| XOR self-cancel | `a ^ a = 0`, `a ^ 0 = a` — used to find the "odd one out" in an array |

### Where it shows up
- Subset enumeration: iterate `for (int mask = 0; mask < (1 << n); mask++)` to try all 2^n subsets
- Bitmask DP (traveling salesman, assignment problems)
- XOR tricks: "find the single number that appears once" (LeetCode 136), XOR prefix sums for range XOR queries

---

## 9. Euler's Totient Function (φ)

### Why it matters
`φ(n)` counts how many integers in `[1, n]` are coprime to `n`. It's the backbone of problems involving coprimality counts and shows up in modular inverse theory for non-prime moduli.

### The idea
Formula: `φ(n) = n * Π(1 - 1/p)` for every distinct prime factor `p` of `n`.

```cpp
long long phi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;   // n itself is a leftover prime factor
    return result;
}
```

### Complexity
- Single value: O(√n)
- Precompute for all values up to N (sieve-style): O(N log log N)

### Where it shows up
- Counting coprime pairs
- Modular inverse when the modulus isn't prime (Euler's theorem generalizes Fermat's little theorem: `a^φ(m) ≡ 1 (mod m)` when `gcd(a,m)=1`)

---

## 10. Divisors — Counting and Summing

### Why it matters
"Count all divisors of n", "find sum of divisors", "smallest number with exactly k divisors" — a recurring problem family.

### Finding all divisors of one number — O(√n)
```cpp
vector<int> getDivisors(int n) {
    vector<int> divs;
    for (int i = 1; (long long)i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    return divs;
}
```

### Divisor count/sum for every number up to N — sieve-style, O(N log N)
Instead of factorizing each number separately, let every number `i` "announce" itself to all its multiples — same spirit as the Sieve of Eratosthenes.
```cpp
vector<int> divisorCount(int n) {
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            cnt[j]++;
    return cnt;
}
```

---

## 11. Catalan Numbers

### Why it matters
A specific counting sequence (`1, 1, 2, 5, 14, 42, ...`) that shows up disguised in a surprising number of problems: valid parenthesis combinations, binary search tree counts, triangulating a polygon, non-crossing paths on a grid.

### The formula
`C(n) = (2n)Cn / (n+1)` — computable with the nCr machinery from section 7.

Recurrence form (useful for DP): `C(n) = Σ C(i) * C(n-1-i)` for `i = 0` to `n-1`, with `C(0) = 1`.

### Recognize it when you see
- "Number of valid parenthesis strings with n pairs" → `C(n)`
- "Number of unique BSTs with n nodes" → `C(n)`
- "Number of ways to triangulate a convex polygon with n+2 sides" → `C(n)`

---

## 12. Matrix Exponentiation

### Why it matters
Any linear recurrence (Fibonacci and its relatives) can be computed in **O(log n)** instead of O(n) by expressing the recurrence as matrix multiplication and applying binary exponentiation (section 1) to the matrix.

### The idea for Fibonacci
```
| F(n+1) |   | 1 1 |   | F(n)   |
| F(n)   | = | 1 0 | * | F(n-1) |
```
Raise the `[[1,1],[1,0]]` matrix to the `n`th power using the same binary-exponentiation loop as section 1, but with matrix multiplication instead of scalar multiplication.

```cpp
typedef vector<vector<long long>> Matrix;
const long long MOD = 1e9 + 7;

Matrix multiply(Matrix a, Matrix b) {
    int n = a.size(), m = b[0].size(), k = b.size();
    Matrix res(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int p = 0; p < k; p++)
                res[i][j] = (res[i][j] + a[i][p] * b[p][j]) % MOD;
    return res;
}

Matrix matPower(Matrix base, long long n) {
    int sz = base.size();
    Matrix result(sz, vector<long long>(sz, 0));
    for (int i = 0; i < sz; i++) result[i][i] = 1;   // identity matrix
    while (n > 0) {
        if (n & 1) result = multiply(result, base);
        base = multiply(base, base);
        n >>= 1;
    }
    return result;
}
```

### Complexity
- O(d^3 log n) where `d` is the matrix dimension (recurrence order)

### Where it shows up
- Fibonacci-type recurrences with huge `n` (up to 10^18)
- Counting paths of length `n` in a graph (adjacency matrix raised to the `n`th power)

---

## 13. Probability & Expected Value Basics

### Why it matters
A recurring DSA/interview category: "expected number of steps", "probability of an event" — usually solvable with linearity of expectation, not full simulation.

### Key rule: Linearity of Expectation
`E[X + Y] = E[X] + E[Y]` — **always true**, even if X and Y are dependent. This is the single most useful trick: break a complex random quantity into a sum of simple indicator variables, find each one's expectation, add them up.

Example pattern: "expected number of fixed points in a random permutation of n elements" → sum of n indicator variables, each with probability `1/n` → answer is `1`, no simulation needed.

### Where it shows up
- Randomized algorithm analysis (expected time of quickselect, randomized quicksort)
- "Expected number of moves" style problems

---

## Quick-Reference Table

| Concept | Time Complexity | When to reach for it |
|---|---|---|
| Fast Exponentiation | O(log n) | Any `a^b`, especially with mod, or `b` is huge |
| GCD (Euclidean) | O(log(min(a,b))) | GCD, LCM, coprimality, modular inverse |
| Modular Arithmetic | O(1) per op | Any problem asking "answer mod 10^9+7" |
| isPrime (single check) | O(√n) | Checking one or a few numbers |
| Sieve of Eratosthenes | O(N log log N) | Need primality for *all* numbers up to N |
| Segmented Sieve | O((R-L) log log R + √R log log √R) | Primes in `[L, R]` where R is huge but range is small |
| Combinatorics (nCr) | O(1) per query after O(N) precompute | Counting arrangements/selections, "number of ways" problems |
| Bit Manipulation | O(1)–O(log n) | Subsets, bitmask DP, XOR tricks |
| Euler's Totient | O(√n) single / O(N log log N) sieve | Coprime counting, modular inverse for non-prime mod |
| Divisors (count/sum) | O(√n) single / O(N log N) for all up to N | "Number of divisors", divisor-based DP |
| Catalan Numbers | O(n) via recurrence, O(log n) via nCr formula | Parenthesis matching, BST counts, polygon triangulation |
| Matrix Exponentiation | O(d³ log n) | Linear recurrences (Fibonacci-type) with huge n |
| Probability / Expected Value | Problem-dependent | "Expected number of..." problems via linearity of expectation |

## Practice Problems (to lock these in)
- Fast exponentiation: Codeforces 630I, "Modular Exponentiation" (GfG)
- GCD/LCM: Codeforces 1082A, Euclidean Algorithm variants
- Modular arithmetic: any Codeforces Div 2 problem tagged `math` + `number theory`
- Sieve: Codeforces 27E "Number With The Given Amount Of Divisors", "Count Primes" (LeetCode 204)
- Segmented Sieve: Codeforces 1721D, SPOJ PRIME1
- Combinatorics: LeetCode 62 "Unique Paths", Codeforces 451E
- Bit Manipulation: LeetCode 136 "Single Number", LeetCode 78 "Subsets", Codeforces 1451E1
- Euler's Totient: SPOJ ETF, Codeforces 776A
- Divisors: LeetCode 204 "Count Primes" (adjacent), Codeforces 27E
- Catalan Numbers: LeetCode 96 "Unique Binary Search Trees", LeetCode 22 "Generate Parentheses"
- Matrix Exponentiation: Codeforces 450B "Jzzhu and Sequences", LeetCode 509 (Fibonacci, for the concept)
- Probability: LeetCode 837 "New 21 Game", Codeforces 908D
