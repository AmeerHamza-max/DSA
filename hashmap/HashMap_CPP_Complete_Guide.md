# HashMap in C++ — Complete Guide for LeetCode

C++ companion to the Python HashMap guide. Covers `unordered_map`, `unordered_set`, `map`, and every core pattern with C++ code.

---

## 1. Core Containers

| Container | Ordering | Insert/Search/Delete | Backing |
|---|---|---|---|
| `unordered_map<K,V>` | none | O(1) avg, O(n) worst | hash table |
| `map<K,V>` | sorted by key | O(log n) | red-black tree |
| `unordered_set<K>` | none | O(1) avg | hash table |
| `set<K>` | sorted | O(log n) | red-black tree |

**Default choice for LeetCode:** `unordered_map` / `unordered_set` unless you specifically need sorted keys or ordered iteration.

---

## 2. Syntax Cheat Sheet

```cpp
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, int> m;              // empty map
unordered_map<int, int> m = {{1, 2}, {3, 4}};  // initialize

m[1] = 100;                              // insert / update (creates key if missing!)
m.insert({1, 100});                      // insert only if not present
m.find(1) != m.end();                    // check existence — O(1)
m.count(1);                              // 0 or 1 — also O(1) existence check
m.erase(1);                              // delete key

for (auto& [key, val] : m)               // C++17 structured bindings
    cout << key << " " << val << "\n";

m.size();                                // number of entries
m.empty();                               // true if size == 0

// SAFE access without inserting a default (unlike m[1]):
auto it = m.find(1);
if (it != m.end()) {
    int val = it->second;
}
```

**Critical gotcha:** `m[key]` on a missing key **auto-inserts** `key` with a default-constructed value (0 for int). If you only want to check existence, use `m.find(key)` or `m.count(key)` — never `m[key]` in a condition.

```cpp
unordered_set<int> s;
s.insert(5);
s.find(5) != s.end();      // existence check
s.count(5);                 // existence check (0 or 1)
s.erase(5);
```

---

## 3. Pattern 1 — Frequency Counting

```cpp
unordered_map<int, int> freq;
for (int n : nums)
    freq[n]++;              // safe: default-inserts 0, then increments
```

### Example: Valid Anagram (LC 242)
```cpp
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : t) {
        if (--count[c] < 0) return false;
    }
    return true;
}
```
**Complexity:** O(n) time, O(1) space (bounded to 26 letters).

### Example: Top K Frequent Elements (LC 347)
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int n : nums) count[n]++;

    // min-heap of size k keyed by frequency
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (auto& [num, freq] : count) {
        pq.push({freq, num});
        if (pq.size() > k) pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
```
**Complexity:** O(n log k).

---

## 4. Pattern 2 — Two Sum / Complement Lookup

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;          // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto it = seen.find(complement);
        if (it != seen.end())
            return {it->second, i};
        seen[nums[i]] = i;
    }
    return {};
}
```
**Complexity:** O(n) time, O(n) space. Check *before* inserting the current element to avoid using it twice.

---

## 5. Pattern 3 — Grouping by Key (Signature/Bucketing)

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());      // canonical signature
        groups[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [key, group] : groups)
        result.push_back(group);
    return result;
}
```
**Complexity:** O(n · k log k).

---

## 6. Pattern 4 — Prefix Sum + HashMap (Subarray Sum)

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> seen;
    seen[0] = 1;                            // prefix sum 0 occurs once
    int prefixSum = 0, count = 0;
    for (int n : nums) {
        prefixSum += n;
        if (seen.count(prefixSum - k))
            count += seen[prefixSum - k];
        seen[prefixSum]++;
    }
    return count;
}
```
**Complexity:** O(n) time, O(n) space. Memorize `seen[0] = 1` — it's the single most common bug source in this pattern.

### Example: Continuous Subarray Sum (LC 523)
```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> seen;           // remainder -> earliest index
    seen[0] = -1;
    int prefixSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        int rem = k == 0 ? prefixSum : prefixSum % k;
        if (seen.count(rem)) {
            if (i - seen[rem] > 1) return true;
        } else {
            seen[rem] = i;
        }
    }
    return false;
}
```

---

## 7. Pattern 5 — Sliding Window + HashMap

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;     // char -> last index
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        if (lastSeen.count(c) && lastSeen[c] >= left)
            left = lastSeen[c] + 1;
        lastSeen[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```
**Complexity:** O(n) time, O(min(n, alphabet size)) space.

### Example: Minimum Window Substring (LC 76)
```cpp
string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    int missing = t.size(), left = 0, start = 0, end = 0;
    for (int right = 0; right < s.size(); right++) {
        if (need[s[right]]-- > 0) missing--;

        if (missing == 0) {
            while (left < right && need[s[left]] < 0) {
                need[s[left]]++;
                left++;
            }
            if (end == 0 || right - left + 1 < end - start) {
                start = left;
                end = right + 1;
            }
        }
    }
    return end == 0 ? "" : s.substr(start, end - start);
}
```

---

## 8. Pattern 6 — HashMap as Memoization Cache

```cpp
unordered_map<int, long long> memo;

long long fib(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
```
**Complexity:** turns exponential recursion into O(n). For 2D states use `unordered_map<long long, T>` with an encoded key (e.g. `i * 100000 + j`), or `map<pair<int,int>, T>`.

---

## 9. Pattern 7 — Structure/Relationship Mapping

### Example: Isomorphic Strings (LC 205)
```cpp
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> mapST, mapTS;
    for (int i = 0; i < s.size(); i++) {
        char a = s[i], b = t[i];
        if (mapST.count(a) && mapST[a] != b) return false;
        if (mapTS.count(b) && mapTS[b] != a) return false;
        mapST[a] = b;
        mapTS[b] = a;
    }
    return true;
}
```

### Example: Build Adjacency List
```cpp
unordered_map<int, vector<int>> buildGraph(vector<pair<int,int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (auto& [u, v] : edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);      // omit for directed graphs
    }
    return graph;
}
```

---

## 10. Pattern 8 — HashMap + Design Problems

### Example: LRU Cache (LC 146) — HashMap + Doubly Linked List
```cpp
class LRUCache {
    struct Node {
        int key, val;
        Node* prev; Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> map;
    Node* left;   // dummy head (LRU side)
    Node* right;  // dummy tail (MRU side)

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (!map.count(key)) return -1;
        Node* node = map[key];
        remove(node);
        insert(node);              // move to most-recently-used end
        return node->val;
    }

    void put(int key, int value) {
        if (map.count(key)) remove(map[key]);
        Node* node = new Node(key, value);
        map[key] = node;
        insert(node);
        if (map.size() > capacity) {
            Node* lru = left->next;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
    }
};
```
**Key insight:** the HashMap gives O(1) node lookup by key; the doubly linked list gives O(1) reordering to track recency.

### Example: Insert Delete GetRandom O(1) (LC 380)
```cpp
class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> idx;      // value -> index in vals

public:
    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;
        int i = idx[val];
        int lastVal = vals.back();
        vals[i] = lastVal;             // swap with last
        idx[lastVal] = i;
        vals.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
```

---

## 11. Decision Tree

```
Need frequency of elements?              -> unordered_map<T,int> / Pattern 1
Need to find pair/complement fast?       -> unordered_map value->index / Pattern 2
Need to group items by shared property?  -> unordered_map<key, vector<T>> / Pattern 3
Subarray sum equals K (contiguous)?      -> Prefix sum + unordered_map / Pattern 4
Substring/window with constraint?        -> Sliding window + unordered_map / Pattern 5
Repeated recursive subproblems?          -> Memoization map / Pattern 6
Need bidirectional mapping/graph?        -> Two unordered_maps or adjacency list / Pattern 7
Designing O(1) data structure?           -> unordered_map + vector / Pattern 8
```

---

## 12. Common C++ Pitfalls

- **`m[key]` auto-inserts** a default value if the key is missing — never use it purely to check existence; use `m.count(key)` or `m.find(key)`.
- **Iterator invalidation:** erasing from an `unordered_map` while iterating with a range-for is undefined behavior. Use `it = m.erase(it)` in a manual loop instead.
- **`unordered_map` iteration order is not guaranteed** and can change between runs — never rely on insertion order (use `map` if you need sorted order).
- **Custom key types** (e.g. `pair<int,int>` or `vector<int>`) need a custom hash function for `unordered_map`/`unordered_set` — they aren't hashable by default like in Python:
  ```cpp
  struct pair_hash {
      size_t operator()(const pair<int,int>& p) const {
          return hash<long long>()(((long long)p.first << 32) ^ p.second);
      }
  };
  unordered_map<pair<int,int>, int, pair_hash> m;
  ```
  Alternatively, encode the pair as a single `long long` key (common LeetCode trick: `i * 100000LL + j`).
- **Worst-case O(n) degradation:** adversarial inputs can cause hash collisions; `map` (O(log n) guaranteed) is safer if worst-case matters and input could be adversarial.
- **`#include` requirements:** `<unordered_map>`, `<unordered_set>`, `<map>`, `<set>` — don't forget them; LeetCode usually includes common headers by default but be explicit when in doubt.

---

## 13. Practice List (Roughly Easy → Hard)

| # | Problem | Pattern |
|---|---|---|
| 1 | Two Sum | Complement lookup |
| 242 | Valid Anagram | Frequency counting |
| 217 | Contains Duplicate | Frequency / seen-set |
| 49 | Group Anagrams | Signature grouping |
| 347 | Top K Frequent Elements | Frequency counting + heap |
| 128 | Longest Consecutive Sequence | Seen-set + expansion |
| 560 | Subarray Sum Equals K | Prefix sum + HashMap |
| 523 | Continuous Subarray Sum | Prefix sum + HashMap (remainder) |
| 3 | Longest Substring Without Repeating Characters | Sliding window |
| 76 | Minimum Window Substring | Sliding window |
| 205 | Isomorphic Strings | Structure mapping |
| 290 | Word Pattern | Structure mapping |
| 380 | Insert Delete GetRandom O(1) | HashMap + vector design |
| 146 | LRU Cache | HashMap + linked list design |
| 138 | Copy List with Random Pointer | HashMap as node mapping |
| 133 | Clone Graph | HashMap as node mapping (DFS/BFS) |

---

## 14. Quick Reference — Complexity Summary

| Pattern | Time | Space |
|---|---|---|
| Frequency counting | O(n) | O(n) |
| Complement lookup | O(n) | O(n) |
| Grouping | O(n·k log k) | O(n·k) |
| Prefix sum + map | O(n) | O(n) |
| Sliding window + map | O(n) | O(min(n, alphabet)) |
| Memoization | O(states) | O(states) |
| HashMap design (LRU etc.) | O(1) per op | O(capacity) |
