# 1160. Find Words That Can Be Formed by Characters

## Problem

You are given

- an array of strings `words`
- a string `chars`

A word is **good** if every character in that word can be formed using the characters in `chars`.

Each character in `chars` can only be used **once** for each word.

Return the **sum of lengths** of all good words.

---

## Example 1

Input

```text
words = ["cat","bt","hat","tree"]
chars = "atach"
```

Output

```text
6
```

Explanation

```
cat  -> Possible
bt   -> Not Possible
hat  -> Possible
tree -> Not Possible
```

Answer

```
3 + 3 = 6
```

---

## Example 2

Input

```text
words = ["hello","world","leetcode"]
chars = "welldonehoneyr"
```

Output

```text
10
```

Explanation

```
hello -> Possible
world -> Possible
leetcode -> Not Possible
```

Answer

```
5 + 5 = 10
```

---

# Idea

We only have lowercase English letters.

So instead of using a map, we can store the frequency of every letter in an array of size **26**.

Example

```
chars = "atach"
```

Frequency

```
a = 2
t = 1
c = 1
h = 1
```

Now for every word

1. Count its characters.
2. Compare with `chars`.
3. If every character frequency is less than or equal to `chars`, then it is a good word.

---

# Algorithm

1. Create a frequency array for `chars`.
2. For every word:
   - Create another frequency array.
   - Count all letters in the word.
   - Compare both arrays.
3. If valid, add the word length to the answer.
4. Return the answer.

---

# Dry Run

Input

```text
words = ["cat","bt","hat","tree"]
chars = "atach"
```

### Step 1

Frequency of chars

```
a = 2
t = 1
c = 1
h = 1
```

---

### Word = "cat"

Frequency

```
c = 1
a = 1
t = 1
```

Compare

```
1<=1
1<=2
1<=1
```

Possible

Answer = 3

---

### Word = "bt"

Need

```
b = 1
```

But

```
b = 0
```

Not possible

Answer = 3

---

### Word = "hat"

Need

```
h = 1
a = 1
t = 1
```

Possible

Answer

```
3 + 3 = 6
```

---

### Word = "tree"

Need

```
e = 2
```

Available

```
e = 0
```

Not possible

Final Answer

```
6
```

---

# Code

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int> charFreq(26, 0);

        for(char ch : chars){
            charFreq[ch - 'a']++;
        }

        int ans = 0;

        for(string word : words){

            vector<int> wordFreq(26, 0);

            for(char ch : word){
                wordFreq[ch - 'a']++;
            }

            bool possible = true;

            for(int i = 0; i < 26; i++){
                if(wordFreq[i] > charFreq[i]){
                    possible = false;
                    break;
                }
            }

            if(possible){
                ans += word.length();
            }
        }

        return ans;
    }
};
```

---

# Complexity

Let

```
n = number of words
m = average length of each word
```

Time Complexity

```
O(chars.length + n × (m + 26))
```

Since 26 is constant,

```
O(n × m)
```

Space Complexity

```
O(26)
```

which is

```
O(1)
```

---

# Key Learning

- Frequency array is faster than `unordered_map` for lowercase letters.
- Build the frequency of `chars` only once.
- Compare each word's frequency with `chars`.
- If any letter is required more times than available, the word is invalid.

---

# Interview Tip

Whenever a problem says:

- lowercase English letters
- uppercase English letters
- digits only

Think about using a **fixed-size frequency array** instead of a map. It is simpler, faster, and uses constant space.