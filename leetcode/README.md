## Longest Palindromic Substring

### Approach 1: Expand from the center to the both sides

+ Check whether it is a palindrome while expanding from the center to both sides
+ divide into odd and even cases

## Regular Expression Matching

### Approach 1: Recursion

+ Adding the start position like `isMatch(string s, string p, int ss=0, int ps=0)` is not recommended.

#### Algorithms

```
if p is empty
    return (s is empty)
first_match = s[0] in {p[0], '.'}
if s is empty:
    first_match = false
if len(p) >= 2 && p[1] == '*':
    if isMatch(s, p[2:]) is true:
        return true;
    else: // => first_match && isMatch(s[1:], p)
        if first_match:
            return isMatch(s[1:], p)
        else:
            return false
else:
    return fisrt_match && isMatch(s[1:], p[1:])
```




