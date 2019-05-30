## Longest Palindromic Substring

### Approach 1: Expand from the center to the both sides
Runtime: **24 ms**, faster than 70.13% of C++ online submissions for Longest Palindromic Substring.

Memory Usage: **12.4 MB**, less than 50.17% of C++ online submissions for Longest Palindromic Substring.

+ Check whether it is a palindrome while expanding from the center to both sides
+ divide into odd and even cases

## Regular Expression Matching

### Approach 1: Recursion
Runtime: **212 ms**, faster than 21.85% of C++ online submissions for Regular Expression Matching.

Memory Usage: **15.6 MB**, less than 17.34% of C++ online submissions for Regular Expression Matching.


+ Adding the start position like `isMatch(string s, string p, int ss=0, int ps=0)` is not recommended.

![](../images/regular-expression-matching.svg)


### Approach 2: Dynamic Programming
Runtime: **12 ms**, faster than 67.86% of C++ online submissions for Regular Expression Matching.

Memory Usage: **21.6 MB**, less than 5.16% of C++ online submissions for Regular Expression Matching.

+ `dp[i][j]`: whether s[i:] matches p[j:] or not

#### 1. Top-Down
+ `i` starts from 0 to s.length(), while `j` starts from 0 to p.length()

#### 2. Bottom-up
Runtime: **0 ms**, faster than 100.00% of C++ online submissions for Regular Expression Matching.

Memory Usage: **8.3 MB**, less than 94.97% of C++ online submissions for Regular Expression Matching.


+ `i` starts from s.length() to 0, while `j` starts from p.length() to 0
+ default: `dp[s.length()][p.length()] = true;`


## Longest Valid Parentheses
### Approach 1: Expand from the center to both sides
Runtime: **140 ms**, faster than 7.43% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9.2 MB**, less than 91.05% of C++ online submissions for Longest Valid Parentheses.

+ Pay attention to the array index out of bounds error
+ The basic idea is similar to the even case in Longest Palindromic Substring
+ Try moving to left first, and move to right afterwards


### Approach 2: Naive top pointer
Runtime: **628 ms**, faster than 5.10% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9 MB**, less than 97.53% of C++ online submissions for Longest Valid Parentheses.

+ For current position, check parentheses to the end. O(N^2)

+ Use `top` integer to check if `(` and `)` matches. `top` should not be less than 0

**problems**

`((((((...(` takes O(N^2) times.


### Approach 3: Without extra space (top.cpp)
Runtime: **4 ms**, faster than 99.28% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9.2 MB**, less than 90.71% of C++ online submissions for Longest Valid Parentheses.

+ **Traverse string from the left towards the right and then traverse from the right towards the left.**

+ Use `top` or `left`, `right` which is used by LeetCode solution to capture the numbers of parentheses

+ If the `top` is less than 0, then we should reset `top` to 0 and pointer.

