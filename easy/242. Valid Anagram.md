# 242. Valid Anagram

## Problem Statement
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

### Example 1:
**Input:**  
`s = "anagram"`, `t = "nagaram"`

**Output:**  
`true`

### Example 2:
**Input:**  
`s = "rat"`, `t = "car"`

**Output:**  
`false`

## Constraints:
- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

## Follow-up:
What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## C++ Solution
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(26, 0); // Frequency array for lowercase letters
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;  // Increment count for char in s
            count[t[i] - 'a']--;  // Decrement count for char in t
        }
        for (int c : count) {
            if (c != 0) return false;
        }
        return true;
    }
};
```

