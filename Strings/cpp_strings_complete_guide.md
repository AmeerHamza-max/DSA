# 🧵 Complete C++ Strings Guide — Beginner to LeetCode Expert

---

## 📌 TABLE OF CONTENTS

1. What is a String?
2. How Strings Work in Memory
3. Declaring & Initializing Strings
4. Input & Output
5. String Length & Size
6. Accessing Characters (Indexing)
7. Iterating Over Strings
8. String Modification
9. String Comparison
10. String Concatenation
11. Substrings
12. Searching in Strings
13. Converting Strings ↔ Numbers
14. Character Functions (cctype)
15. String as Array of Characters (char array vs string)
16. Important STL Functions
17. Two Pointer Technique on Strings
18. Sliding Window on Strings
19. Frequency Count (HashMap on Strings)
20. String Reversal Patterns
21. Palindrome Patterns
22. Anagram Patterns
23. Common LeetCode Patterns
24. Practice Problems (Beginner → Advanced)
25. Quick Reference Cheat Sheet

---

## 1. 📖 WHAT IS A STRING?

A string is a **sequence of characters**. In C++, we use the `string` class from the Standard Template Library (STL).

Think of it like a **necklace of beads** — each bead is a character, and the necklace is your string.

```
"hello" → ['h', 'e', 'l', 'l', 'o']
index  →   [0,   1,   2,   3,   4 ]
```

---

## 2. 🧠 HOW STRINGS WORK IN MEMORY

```
string s = "hello";

Memory layout:
[ h ][ e ][ l ][ l ][ o ][\0]
  0    1    2    3    4    5   ← index
```

- Each character takes **1 byte**
- C-style strings end with a **null character `\0`**
- C++ `string` class handles this automatically

---

## 3. 🔧 DECLARING & INITIALIZING STRINGS

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Method 1: Direct assignment
    string s1 = "hello";

    // Method 2: Constructor
    string s2("world");

    // Method 3: Empty string
    string s3 = "";
    string s4;          // also empty

    // Method 4: Repeated character
    string s5(5, 'a');  // "aaaaa"

    // Method 5: Copy from another string
    string s6 = s1;     // "hello"

    // Method 6: Part of another string
    string s7 = s1.substr(1, 3);  // "ell" (start at 1, length 3)

    cout << s1 << endl;  // hello
    cout << s5 << endl;  // aaaaa
    cout << s7 << endl;  // ell

    return 0;
}
```

---

## 4. 📥 INPUT & OUTPUT

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;

    // cin reads ONE word (stops at space)
    cout << "Enter name: ";
    cin >> name;
    cout << "Hello, " << name << endl;

    // getline reads ENTIRE LINE (including spaces)
    cin.ignore(); // clear newline from buffer before getline
    string fullName;
    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Full name: " << fullName << endl;

    return 0;
}
```

> ⚠️ **Common Mistake:** Using `cin >>` before `getline()` without `cin.ignore()` causes `getline` to read an empty line.

---

## 5. 📏 STRING LENGTH & SIZE

```cpp
string s = "hello";

// Both do the same thing
cout << s.length() << endl;  // 5
cout << s.size() << endl;    // 5

// Check if empty
if (s.empty()) {
    cout << "empty!" << endl;
} else {
    cout << "not empty, size = " << s.size() << endl;
}

// Clear a string
s.clear();
cout << s.size() << endl;  // 0
```

---

## 6. 🔢 ACCESSING CHARACTERS (INDEXING)

```cpp
string s = "hello";

// Method 1: Square bracket (fast, no bounds check)
cout << s[0] << endl;   // h
cout << s[4] << endl;   // o

// Method 2: .at() (safe, throws exception if out of bounds)
cout << s.at(1) << endl;  // e

// First and last character
cout << s.front() << endl;  // h
cout << s.back()  << endl;  // o

// Modify a character
s[0] = 'H';
cout << s << endl;  // Hello

// Last index = s.length() - 1
cout << s[s.length() - 1] << endl;  // o
```

---

## 7. 🔄 ITERATING OVER STRINGS

```cpp
string s = "hello";

// Method 1: Index-based loop (most common in interviews)
for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
}
// h e l l o

// Method 2: Range-based for loop
for (char c : s) {
    cout << c << " ";
}

// Method 3: Iterator
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}

// Method 4: Reverse iteration
for (int i = s.length() - 1; i >= 0; i--) {
    cout << s[i];
}
// olleh
```

---

## 8. ✏️ STRING MODIFICATION

```cpp
string s = "hello";

// APPEND: add to end
s += " world";          // "hello world"
s.append("!");          // "hello world!"
s.push_back('?');       // "hello world!?" (adds one char)

// INSERT: add at position
s.insert(5, " beautiful");  // inserts at index 5

// ERASE: remove characters
string t = "hello world";
t.erase(5, 6);          // removes 6 chars starting at index 5 → "hello"
t.pop_back();           // removes last character → "hell"

// REPLACE: replace part of string
string r = "I love cats";
r.replace(7, 4, "dogs");   // start=7, length=4, new="dogs" → "I love dogs"

// REVERSE a string
#include <algorithm>
string rev = "hello";
reverse(rev.begin(), rev.end());
cout << rev;  // "olleh"

// SORT a string (sorts characters)
string sorted = "dcba";
sort(sorted.begin(), sorted.end());
cout << sorted;  // "abcd"
```

---

## 9. ⚖️ STRING COMPARISON

```cpp
string a = "apple";
string b = "banana";
string c = "apple";

// == and != operators
cout << (a == c) << endl;   // 1 (true)
cout << (a != b) << endl;   // 1 (true)

// Lexicographic comparison (dictionary order)
cout << (a < b) << endl;    // 1 (true, 'a' < 'b')
cout << (a > b) << endl;    // 0 (false)

// .compare() method
// Returns 0 if equal, negative if a < b, positive if a > b
int result = a.compare(b);
if (result == 0)      cout << "equal";
else if (result < 0)  cout << "a comes first";
else                  cout << "b comes first";
```

---

## 10. ➕ STRING CONCATENATION

```cpp
string s1 = "hello";
string s2 = " world";

// Method 1: + operator
string s3 = s1 + s2;           // "hello world"

// Method 2: += operator
s1 += s2;                       // s1 becomes "hello world"

// Method 3: append
string s4 = "hello";
s4.append(" world");

// Concatenate number with string (WRONG and RIGHT)
int num = 42;

// ❌ WRONG: string + int directly gives error
// string bad = "Number: " + num;  // ERROR!

// ✅ CORRECT: convert int to string first
string good = "Number: " + to_string(num);  // "Number: 42"
```

---

## 11. ✂️ SUBSTRINGS

```cpp
string s = "hello world";

// substr(start_index, length)
string sub1 = s.substr(0, 5);   // "hello"   (from 0, 5 chars)
string sub2 = s.substr(6, 5);   // "world"   (from 6, 5 chars)
string sub3 = s.substr(6);      // "world"   (from 6 to end)

cout << sub1 << endl;
cout << sub2 << endl;
cout << sub3 << endl;

// ⚠️ Common LeetCode usage:
// Extract all substrings of a string
string str = "abc";
for (int i = 0; i < str.length(); i++) {
    for (int j = 1; j <= str.length() - i; j++) {
        cout << str.substr(i, j) << endl;
    }
}
// a, ab, abc, b, bc, c
```

---

## 12. 🔍 SEARCHING IN STRINGS

```cpp
string s = "hello world hello";

// find() returns index of first occurrence, or string::npos if not found
int pos = s.find("hello");      // 0 (first occurrence)
int pos2 = s.find("hello", 1);  // 12 (search from index 1)
int pos3 = s.find("xyz");       // string::npos (not found)

if (pos3 == string::npos) {
    cout << "Not found!" << endl;
}

// rfind() - find LAST occurrence
int last = s.rfind("hello");    // 12

// find_first_of() - find first char that is IN the set
string vowels = "aeiou";
int vowelPos = s.find_first_of(vowels);  // index of first vowel in s

// find_last_of() - find last char in the set
int lastVowel = s.find_last_of(vowels);

// Check if string CONTAINS a substring
if (s.find("world") != string::npos) {
    cout << "Contains 'world'" << endl;
}
```

---

## 13. 🔄 CONVERTING STRINGS ↔ NUMBERS

```cpp
#include <string>
using namespace std;

// INT → STRING
int n = 42;
string s = to_string(n);       // "42"

double d = 3.14;
string ds = to_string(d);      // "3.140000"

// STRING → INT
string numStr = "123";
int num = stoi(numStr);        // 123  (string to int)

// STRING → LONG
string bigStr = "9999999999";
long long big = stoll(bigStr); // (string to long long)

// STRING → DOUBLE
string floatStr = "3.14";
double f = stod(floatStr);     // 3.14 (string to double)

// CHARACTER → INT (ASCII value)
char c = 'A';
int ascii = (int)c;            // 65

// Get digit value of a character
char digit = '7';
int val = digit - '0';         // 7  ← very common in interviews!

// Get position of a letter (a=0, b=1, ...)
char letter = 'e';
int pos = letter - 'a';        // 4
```

---

## 14. 🔡 CHARACTER FUNCTIONS (cctype)

```cpp
#include <cctype>

char c = 'A';

// Check type
isalpha(c);    // true if letter (a-z or A-Z)
isdigit(c);    // true if digit (0-9)
isalnum(c);    // true if letter OR digit
isspace(c);    // true if whitespace (space, tab, newline)
isupper(c);    // true if uppercase
islower(c);    // true if lowercase

// Convert case
toupper(c);    // 'A' → 'A' (already upper)
tolower(c);    // 'A' → 'a'
toupper('z');  // 'Z'
tolower('Z');  // 'z'

// ===== Example: Count vowels in a string =====
string s = "Hello World";
int vowelCount = 0;
for (char ch : s) {
    ch = tolower(ch);  // normalize to lowercase
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        vowelCount++;
    }
}
cout << "Vowels: " << vowelCount << endl;  // 3
```

---

## 15. 📦 CHAR ARRAY vs STRING CLASS

```cpp
// C-style char array (OLD way)
char arr[] = "hello";         // null-terminated
char arr2[10] = "world";

// C++ string class (PREFERRED)
string s = "hello";

// Why string class is better:
// 1. Dynamic size (no fixed length)
// 2. Rich methods (.find, .substr, etc.)
// 3. Easy concatenation with +
// 4. Safe (no buffer overflow)

// Convert between them
string cpp_str = "hello";
const char* c_str = cpp_str.c_str();   // C++ string → char array
string back = string(c_str);            // char array → C++ string
```

---

## 16. 🛠️ IMPORTANT STL FUNCTIONS FOR STRINGS

```cpp
#include <algorithm>
#include <string>
using namespace std;

string s = "hello world";

// REVERSE
reverse(s.begin(), s.end());         // "dlrow olleh"

// SORT characters
sort(s.begin(), s.end());            // sorted alphabetically

// COUNT occurrences of a character
int cnt = count(s.begin(), s.end(), 'l');  // count 'l's

// UNIQUE - removes consecutive duplicates
string dup = "aabbcc";
sort(dup.begin(), dup.end());         // sort first
auto it = unique(dup.begin(), dup.end());
dup.erase(it, dup.end());            // "abc"

// MIN and MAX character
char minChar = *min_element(s.begin(), s.end());
char maxChar = *max_element(s.begin(), s.end());

// CHECK if SORTED
bool sorted = is_sorted(s.begin(), s.end());

// TRANSFORM (apply function to each char)
transform(s.begin(), s.end(), s.begin(), ::toupper);  // to uppercase
transform(s.begin(), s.end(), s.begin(), ::tolower);  // to lowercase
```

---

## 17. 👆👆 TWO POINTER TECHNIQUE ON STRINGS

The two pointer technique uses two indices — one from the left, one from the right — and moves them toward each other.

**Use cases:** Palindrome check, reversing, removing duplicates

```cpp
// ===== Check if string is a Palindrome =====
bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;   // mismatch → not palindrome
        }
        left++;
        right--;
    }
    return true;
}

// ===== Reverse a string in-place =====
void reverseString(string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// ===== Remove spaces using two pointers =====
string removeSpaces(string s) {
    int write = 0;
    for (int read = 0; read < s.size(); read++) {
        if (s[read] != ' ') {
            s[write++] = s[read];
        }
    }
    return s.substr(0, write);
}
```

---

## 18. 🪟 SLIDING WINDOW ON STRINGS

A window (subarray/substring) slides across the string. Very common in LeetCode string problems.

**Types:**
- Fixed window size
- Variable window (expand/shrink based on condition)

```cpp
// ===== Max sum of k consecutive characters (ASCII values) =====
int maxSumWindow(string s, int k) {
    int windowSum = 0;
    // Build first window
    for (int i = 0; i < k; i++) {
        windowSum += s[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < s.length(); i++) {
        windowSum += s[i];          // add new char
        windowSum -= s[i - k];     // remove old char
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// ===== Longest substring without repeating characters (Variable Window) =====
int lengthOfLongestSubstring(string s) {
    int freq[256] = {0};    // frequency of each character
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;   // add right char to window

        // Shrink window while we have duplicates
        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

---

## 19. 📊 FREQUENCY COUNT (HASHMAP ON STRINGS)

Counting how often each character appears is one of the MOST common string patterns.

```cpp
#include <unordered_map>
using namespace std;

// Method 1: Array (only lowercase a-z)
void frequencyArray(string s) {
    int freq[26] = {0};  // index 0 = 'a', 25 = 'z'
    for (char c : s) {
        freq[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << (char)('a' + i) << ": " << freq[i] << endl;
        }
    }
}

// Method 2: unordered_map (any character)
void frequencyMap(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    for (auto& p : freq) {
        cout << p.first << ": " << p.second << endl;
    }
}

// ===== Check if two strings are ANAGRAMS =====
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }
    return true;
}
```

---

## 20. 🔃 STRING REVERSAL PATTERNS

```cpp
// ===== Reverse entire string =====
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// ===== Reverse words in a sentence =====
// "hello world" → "world hello"
string reverseWords(string s) {
    // Step 1: reverse entire string
    reverse(s.begin(), s.end());
    // "dlrow olleh"

    // Step 2: reverse each word
    int n = s.length(), start = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    return s;  // "world hello"
}

// ===== Rotate string left by k =====
// "abcde", k=2 → "cdeab"
string rotateLeft(string s, int k) {
    k = k % s.length();   // handle k > length
    return s.substr(k) + s.substr(0, k);
}

// ===== Rotate string right by k =====
// "abcde", k=2 → "deabc"
string rotateRight(string s, int k) {
    k = k % s.length();
    return s.substr(s.length() - k) + s.substr(0, s.length() - k);
}
```

---

## 21. 🪞 PALINDROME PATTERNS

```cpp
// ===== Basic palindrome check =====
bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

// ===== Palindrome check ignoring non-alphanumeric (LeetCode 125) =====
bool isPalindromeLC(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        // Skip non-alphanumeric
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;

        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}

// ===== Expand around center (for Longest Palindromic Substring) =====
// Returns the longest palindrome length centered at (left, right)
int expandFromCenter(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // length
}

string longestPalindrome(string s) {
    int start = 0, maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        int odd  = expandFromCenter(s, i, i);     // odd length
        int even = expandFromCenter(s, i, i + 1); // even length
        int best = max(odd, even);

        if (best > maxLen) {
            maxLen = best;
            start = i - (best - 1) / 2;
        }
    }
    return s.substr(start, maxLen);
}
```

---

## 22. 🔀 ANAGRAM PATTERNS

```cpp
// ===== Check anagram =====
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int freq[26] = {};
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;
    for (int x : freq) if (x != 0) return false;
    return true;
}

// ===== Group anagrams together (LeetCode 49) =====
#include <unordered_map>
#include <vector>
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());   // sorted version = key
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& p : mp) {
        result.push_back(p.second);
    }
    return result;
}

// ===== Count anagram substrings (LeetCode 438 - Find all anagrams) =====
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;

    int freq[26] = {}, window[26] = {};
    for (char c : p) freq[c - 'a']++;

    int k = p.size();
    for (int i = 0; i < s.size(); i++) {
        window[s[i] - 'a']++;
        if (i >= k) window[s[i - k] - 'a']--;
        if (equal(freq, freq + 26, window)) {
            result.push_back(i - k + 1);
        }
    }
    return result;
}
```

---

## 23. 🏆 COMMON LEETCODE STRING PATTERNS

### Pattern 1: Split string by delimiter

```cpp
#include <sstream>
vector<string> splitString(string s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
// splitString("hello world foo", ' ') → ["hello", "world", "foo"]
```

### Pattern 2: Count words

```cpp
int countWords(string s) {
    int count = 0;
    bool inWord = false;
    for (char c : s) {
        if (c != ' ' && !inWord) {
            count++;
            inWord = true;
        } else if (c == ' ') {
            inWord = false;
        }
    }
    return count;
}
```

### Pattern 3: Remove duplicates from string

```cpp
string removeDups(string s) {
    string result = "";
    bool seen[256] = {};
    for (char c : s) {
        if (!seen[c]) {
            seen[c] = true;
            result += c;
        }
    }
    return result;
}
```

### Pattern 4: String compression

```cpp
// "aaabbc" → "a3b2c1"
string compress(string s) {
    string result = "";
    int i = 0;
    while (i < s.size()) {
        char curr = s[i];
        int count = 0;
        while (i < s.size() && s[i] == curr) {
            count++;
            i++;
        }
        result += curr + to_string(count);
    }
    return result;
}
```

### Pattern 5: Check substring / Pattern matching

```cpp
// Naive pattern matching
bool contains(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        if (text.substr(i, m) == pattern) return true;
    }
    return false;
}

// Better: use built-in find
bool containsBuiltin(string text, string pattern) {
    return text.find(pattern) != string::npos;
}
```

### Pattern 6: Zigzag / Interleave strings

```cpp
// Check if s3 is formed by interleaving s1 and s2
// (LeetCode 97 - Interleaving String)
bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size();
    if (n + m != s3.size()) return false;

    // dp[i][j] = can we form s3[0..i+j] using s1[0..i] and s2[0..j]
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    for (int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                       (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[n][m];
}
```

---

## 24. 🎯 PRACTICE PROBLEMS

### 🟢 BEGINNER (Build Confidence)

```
1. Reverse a string (without using built-in reverse)
   Input: "hello" → Output: "olleh"

2. Count vowels and consonants in a string
   Input: "hello world" → Vowels: 3, Consonants: 7

3. Check if a string is a palindrome
   Input: "racecar" → true | "hello" → false

4. Count occurrences of a character
   Input: "banana", 'a' → 3

5. Convert all lowercase to uppercase without toupper()
   Hint: 'A' = 65, 'a' = 97, difference = 32

6. Remove all spaces from a string
   Input: "hello world" → "helloworld"
```

### 🟡 INTERMEDIATE (Pattern Recognition)

```
7. Find first non-repeating character
   Input: "aabbcde" → 'c'
   (LeetCode 387)

8. Check if two strings are anagrams
   Input: "listen", "silent" → true

9. Longest common prefix in array of strings
   Input: ["flower","flow","flight"] → "fl"
   (LeetCode 14)

10. Count and say sequence
    1 → "1", 11 → "21", 21 → "1211", ...
    (LeetCode 38)

11. Longest substring without repeating characters
    Input: "abcabcbb" → 3 ("abc")
    (LeetCode 3)

12. Valid parentheses using string operations
    Input: "()" → true | "([)]" → false
    (LeetCode 20)
```

### 🔴 ADVANCED (Interview Level)

```
13. Longest palindromic substring
    Input: "babad" → "bab" or "aba"
    (LeetCode 5)

14. Minimum window substring
    Input: s="ADOBECODEBANC", t="ABC" → "BANC"
    (LeetCode 76)

15. Group anagrams
    Input: ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    (LeetCode 49)

16. String to Integer (atoi)
    Handle +/- sign, overflow, non-digit chars
    (LeetCode 8)
```

### 🏆 CHALLENGE (Competition Level)

```
17. Implement KMP (Knuth-Morris-Pratt) string matching algorithm
    - Build failure function
    - Search pattern in text in O(n+m)
    (LeetCode 28 - Find Index of First Occurrence)

18. Wildcard Matching with * and ?
    (LeetCode 44)

19. Edit Distance (Levenshtein)
    Minimum operations to convert s1 to s2
    (LeetCode 72)

20. Distinct Subsequences
    (LeetCode 115)
```

---

## 25. 📋 QUICK REFERENCE CHEAT SHEET

```
╔══════════════════════════════════════════════════════════╗
║                 C++ STRING CHEAT SHEET                   ║
╠══════════════════════════════════════════════════════════╣
║ DECLARATION          string s = "hello";                 ║
║ LENGTH               s.length()  or  s.size()           ║
║ EMPTY                s.empty()                           ║
║ ACCESS CHAR          s[i]   or   s.at(i)                ║
║ FIRST/LAST           s.front()  /  s.back()             ║
║ SUBSTRING            s.substr(start, len)                ║
║ FIND                 s.find("sub")  →  index/npos       ║
║ APPEND               s += "x"  or  s.append("x")        ║
║ INSERT               s.insert(pos, "x")                  ║
║ ERASE                s.erase(pos, len)                   ║
║ REPLACE              s.replace(pos, len, "new")          ║
║ CLEAR                s.clear()                           ║
║ REVERSE              reverse(s.begin(), s.end())         ║
║ SORT                 sort(s.begin(), s.end())            ║
║ INT→STRING           to_string(42)                       ║
║ STRING→INT           stoi("42")                          ║
║ CHAR IS LETTER       isalpha(c)                          ║
║ CHAR IS DIGIT        isdigit(c)                          ║
║ TO UPPERCASE         toupper(c)                          ║
║ TO LOWERCASE         tolower(c)                          ║
║ CHAR TO INT          c - '0'   (for digits)             ║
║ CHAR POSITION        c - 'a'   (for letters)            ║
╚══════════════════════════════════════════════════════════╝

╔══════════════════════════════════════════════════════════╗
║              INTERVIEW PATTERN CHEAT SHEET               ║
╠══════════════════════════════════════════════════════════╣
║ Two Pointer      → Palindrome, Reverse, Compare         ║
║ Sliding Window   → Longest/shortest substring           ║
║ Frequency Array  → Anagram, distinct chars              ║
║ HashMap          → First unique, group anagrams         ║
║ Expand Center    → Palindromic substring                ║
║ Stack            → Valid parentheses, decode string     ║
║ Prefix String    → Longest common prefix                ║
╚══════════════════════════════════════════════════════════╝
```

---

## 🧠 THINKING APPROACH FOR STRING PROBLEMS

Before coding, always ask:

```
1. What is the INPUT format? (single string, array, pair?)
2. What does the OUTPUT look like?
3. Do I need to consider case sensitivity?
4. What about spaces / special characters?
5. Is there a brute force O(n²) approach first?
6. Can I optimize with sliding window / two pointer / hashmap?
7. What is the time and space complexity?
```

---

## 🔑 KEY TAKEAWAYS

- Strings are **0-indexed** — always check boundaries
- Use `s.length() - 1` for the last index
- `string::npos` = -1 equivalent for "not found"
- `c - '0'` converts digit character to integer
- `c - 'a'` gives position of letter (a=0, z=25)
- Frequency arrays of size 26 cover all lowercase letters
- `substr`, `find`, `erase`, `replace` are your bread and butter
- Most LeetCode string problems use: Two Pointer, Sliding Window, or Frequency Map
- Always think about **edge cases**: empty string, single char, all same chars

---

*Made for aspiring software engineers — from zero to LeetCode hero 🚀*
