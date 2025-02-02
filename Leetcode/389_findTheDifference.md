# [389. Find the Difference](https://leetcode.com/problems/find-the-difference/) 🌟

You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

### Brute force

-   Traverse every char in s and check if it is present in t or not.
-   if not present, return the char.
-   **TC: O(n^2)**
-   **SC: O(1)**

### sorting

-   Sort s and t.
-   traverse s and t and check if they are equal or not.
-   if not equal, return the char.
-   **TC: O(nlogn)**
-   **SC: O(1)**, excluding the sorting space.

### Code

```cpp
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) return t[i];
        }
        return t[n];
    }
};
```

### Hashing

-   We can use hashmap to store the frequency of characters.
-   first traverse `s` and increase frequency and then traverse `t` and decrease frequency.
-   Now traverse map anf if `it.second<0` return `it.first`.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> mp;
        for (auto x : s) mp[x]++;
        for (auto x : t) mp[x]--;
        for (auto x : mp) {
            if (x.second < 0) return x.first;
        }
        return 'a';
    }
};
```

### Bit Manipulation

-   We can use bit manipulation to solve this problem.
-   We can use XOR to find the difference.
-   **TC: O(n)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        char res = 0;
        for (auto x : s) res ^= x;
        for (auto x : t) res ^= x;
        return res;
    }
};
```
