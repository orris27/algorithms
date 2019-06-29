## 01. Two Sum
### Approach 1: Brute Force
Time Complexity: O(N^2), Space Complexity: O(1)

Runtime: **540 ms**, faster than 5.14% of C++ online submissions for Two Sum.

Memory Usage: **9.4 MB**, less than 73.20% of C++ online submissions for Two Sum.

+ Check all the pairs

### Approach 2: One-pass Hash Table
Time Complexity: O(N), Space Complexity: O(N)

Runtime: **4 ms**, faster than 99.94% of C++ online submissions for Two Sum.

Memory Usage: **10.3 MB**, less than 27.80% of C++ online submissions for Two Sum.

+ For a given number, look up its complement's index using hash table



## 03. Longest Substring Without Repeating Characters
### Approach 1: Sliding Window

Runtime: **24 ms**, faster than 60.85% of C++ online submissions for Longest Substring Without Repeating Characters.

Memory Usage: **12.6 MB**, less than 63.06% of C++ online submissions for Longest Substring Without Repeating Characters.

+ Mark the head and tail of the longest substring with two points. Since the longest substing without repeating characters is also a substring internally, if the tail pointer moves to the right and encounters a character that has already appears in the marked substring, the pointer of head only needs to move to the right to meet the condition.

+ C++ set

### Approach 2: Sliding Window Optimized
Time Complexity: O(N), Space Complexity: HashMap O(min(m, n)), Table O(m), m is the size of the charset

Runtime: **20 ms**, faster than 77.60% of C++ online submissions for Longest Substring Without Repeating Characters.

Memory Usage: **10.8 MB**, less than 75.30% of C++ online submissions for Longest Substring Without Repeating Characters.


+ Build a hashmap to store the mapping of content to subscrtips.
+ The `max` function is used to filter out elements with subscripts less than l

## 04. Median of Two Sorted Arrays
### Approach 1: Recursive Approach
Time Complexity: O(log(m+n)), Space Complexity: O(1)

Runtime: **20 ms**, faster than 92.31% of C++ online submissions for Median of Two Sorted Arrays.

Memory Usage: **9.8 MB**, less than 67.90% of C++ online submissions for Median of Two Sorted Arrays.

+ Cut two arrays into 2 parts.
+ 1. the length of left parts = the length of right parts
+ 2. the maximum element in left parts <= the minimum element in right parts
+ binary search
+ See details [here](https://leetcode.com/articles/median-of-two-sorted-arrays/)



## 05. Longest Palindromic Substring

### Approach 1: Expand from the center to the both sides
Runtime: **24 ms**, faster than 70.13% of C++ online submissions for Longest Palindromic Substring.

Memory Usage: **12.4 MB**, less than 50.17% of C++ online submissions for Longest Palindromic Substring.

+ Check whether it is a palindrome while expanding from the center to both sides
+ divide into odd and even cases

## 10. Regular Expression Matching

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



## 11. Container With Most Water
### Approach 1: Brute Force
### Approach 2: Two Pointer Approach
Time Complexity: O(N), Space Complexity: O(1)

Runtime: **16 ms**, faster than 97.98% of C++ online submissions for Container With Most Water.

Memory Usage: **9.9 MB**, less than 55.66% of C++ online submissions for Container With Most Water.

+ Move two pointers inward from both sides. If a specfic move is unlikely to have better results in the future, the pointer will not move.



## 22. Generate Parantheses
### Approach 1: Brute Force
Time: O(N * 2^(2N)) Space: O(N * 2^(2N))

+ Generate all sequences and check whether a sequence is valid

### Approach 2: Backtracking
Time: O((4^N) / sqrt(N)) Space: O((4^N) / sqrt(N))

Runtime: **8 ms**, faster than 85.74% of C++ online submissions for Generate Parentheses.

Memory Usage: **17.5 MB**, less than 25.55% of C++ online submissions for Generate Parentheses.

+ Keep track of the number of opening and closing brackets we have placed so far, and add brackets only when we know it will remain a valid sequence


### Approach 3: Closure Number
Time: O((4^N) / sqrt(N)) Space: O((4^N) / sqrt(N))

Runtime: **8 ms**, faster than 84.70% of C++ online submissions for Generate Parentheses.

Memory Usage: **14.6 MB**, less than 72.60% of C++ online submissions for Generate Parentheses.

+ For each closure number `c`, the starting and ending brackets must be at index `c` and `2 * c + 1`. The `2*c` elements between must also be a valid sequence, plus the rest of the elements must be a valid sequence.


## 31. Next Permutation
### Approach 1: Brute Force
Time: O(N!) Space: O(N)

### Approach 2: Single Pass Approach
Time: O(N) Space: O(1)

Runtime: **8 ms**, faster than 92.77% of C++ online submissions for Next Permutation.

Memory Usage: **8.5 MB**, less than 89.81% of C++ online submissions for Next Permutation.

Cases

+ `x x x 2 3` => `x x x 3 2`
+  `x x x a b c1 c2 ...`, where b > a and b > c1 > c2 > ... => `x x x c_i ... c_{i-1} a ... c2 c1 b` (find i that satisfies c\_i > a and c\_{i+1} <= a); 
+ `4 3 2 1` => `1 2 3 4`



## 32. Longest Valid Parentheses
### Approach 1: Expand from the center to both sides
Runtime: **140 ms**, faster than 7.43% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9.2 MB**, less than 91.05% of C++ online submissions for Longest Valid Parentheses.

+ Pay attention to the array index out of bounds error
+ The basic idea is similar to the even case in Longest Palindromic Substring
+ Try moving to left first, and move to right afterwards


### Approach 2: Brute Force
Runtime: **628 ms**, faster than 5.10% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9 MB**, less than 97.53% of C++ online submissions for Longest Valid Parentheses.

+ For current position, check parentheses to the end. O(N^2)

+ Use `top` integer to check if `(` and `)` matches. `top` should not be less than 0

**problems**

`((((((...(` takes O(N^2) times.


### Approach 3: Without extra space (top.cpp)
Time Complexity: O(N), Space Complexity: O(1)

Runtime: **4 ms**, faster than 99.28% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9.2 MB**, less than 90.71% of C++ online submissions for Longest Valid Parentheses.

+ **Traverse string from the left towards the right and then traverse from the right towards the left.**: if traverse only once, `(()` is a problem.

+ Use `top` or `left`, `right` which is used by LeetCode solution to capture the numbers of parentheses

+ If the `top` is less than 0, then we should reset `top` to 0 and pointer.

### Approach 4: Stack
Time Complexity: O(N), Space Complexity: O(N)

Runtime: **8 ms**, faster than 90.98% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9.5 MB**, less than 73.95% of C++ online submissions for Longest Valid Parentheses.

+ Push & Pop corresponds to '(' and ')' respectly
+ To calculate the length of valid parentheses, their indices are required to be store in the stack
+ Push -1 at the begining
+ If ')' is encountered, pop + (if empty push) + subtract

### Approach 5: Dynamic Programming
Time Complexity: O(N), Space Complexity: O(N)

Runtime: **8 ms**, faster than 90.98% of C++ online submissions for Longest Valid Parentheses.

Memory Usage: **9.3 MB**, less than 89.47% of C++ online submissions for Longest Valid Parentheses.

+ i-th element of `dp` represents the length of longest valid parentheses ending at s[i]
+ `dp[i]` depends on `dp[i - 1]`, `dp[i - 2]` and `dp[i - dp[i-2] - 2]`.




## 33. Search in Rotated Array
### Approach 1: Binary Search
Time: O(logN)

Runtime: **4 ms**, faster than 93.93% of C++ online submissions for Search in Rotated Sorted Array.

Memory Usage: **8.7 MB**, less than 83.60% of C++ online submissions for Search in Rotated Sorted Array.

+ Find the first element that is just smaller than the first element. Take care of the case that the array is not rotated, such as `[1, 3]`
+ Apply binary search while computing the modulo


## 34. Find First and Last Position of Elements in Sorted Array
### Approach 1: Brute Force
Time: O(N) Space: O(1)

### Approach 2: Binary Search
Time: O(logN) Space: O(1)

Runtime: **8 ms**, faster than 94.92% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

Memory Usage: **10.6 MB**, less than 42.10% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

+ a modified binary search

## 39. Combination Sum
### Approach 1: Backtracking
Runtime: **116 ms**, faster than 7.98% of C++ online submissions for Combination Sum.

Memory Usage: **45.1 MB**, less than 6.39% of C++ online submissions for Combination Sum.

+ Compute the possible numbers of current elements which determine how many can we add it to our list. Then we go to the next element and do the same thing

### Approach 2: Backtracking with Pruning
Runtime: **40 ms**, faster than 25.82% of C++ online submissions for Combination Sum.

Memory Usage: **19.5 MB**, less than 17.09% of C++ online submissions for Combination Sum.

+ Sort the candidates and do not search if current element is larger than target.

## 40. Combination Sum2
### Approach 1: Backtracking with Pruning
Runtime: **16 ms**, faster than 42.37% of C++ online submissions for Combination Sum II.

Memory Usage: **11.1 MB**, less than 31.35% of C++ online submissions for Combination Sum II.

+ Transform combination sum2 problem to combination sum.



## 41. First Missing Positive
### Approach 1: Counting Sort Approach
Runtime: **4 ms**, faster than 87.32% of C++ online submissions for First Missing Positive.

Memory Usage: **8.8 MB**, less than 50.06% of C++ online submissions for First Missing Positive.

+ The first missing positive must be between 1 to N (inclusive)
+ Put the each element in its right place. In this case, keep the rule of `a[i-1] = i`.



## 46. Permutations

### Approach 1: Brute Force

### Approach 2: Backtracking

Runtime: **12 ms**, faster than 90.37% of C++ online submissions forPermutations.

Memory Usage: **9.6 MB**, less than 35.43% of C++ online submissions forPermutations.

+ select next element by swapping


## 48. Rotate Image
### Approach 1: Const Space
Runtime: **4 ms**, faster than 91.76% of C++ online submissions for Rotate Image.

Memory Usage: **9 MB**, less than 61.34% of C++ online submissions for Rotate Image.

+ Record four elements and assign corresponding values to them.
### Approach 2: Magic Approach
Time: O(N^2)

Runtime: **4 ms**, faster than 91.76% of C++ online submissions for Rotate Image.

Memory Usage: **8.9 MB**, less than 93.69% of C++ online submissions for Rotate Image.

+ Clockwise: reverse top to down, and then swap the symmetry
+ anti-clockwise: swap the symmetry, and then reverse top to down

### Approach 3: Swap: Simplified version of approach 1
Runtime: **4 ms**, faster than 91.76% of C++ online submissions for Rotate Image.

Memory Usage: **8.8 MB**, less than 99.81% of C++ online submissions for Rotate Image.

+ [Rotate an n x n matrix](https://www.youtube.com/watch?v=Jtu6dJ0Cb94)


## 51. N-Queens
### Approach 1: Backtracking with Prunning
Runtime: **4 ms**, faster than 99.14% of C++ online submissions for N-Queens.

Memory Usage: **11.7 MB**, less than 28.92% of C++ online submissions for N-Queens.

+ Use int array to represent the positio of queen in a specfic row
+ Select the next position if and only if it is not in the same row, column or diagonal as previous points

## 54. Spiral Matrix
### Approach 1: Simulation
Runtime: **0 ms**, faster than 100.00% of C++ online submissions for Spiral Matrix.

Memory Usage: **8.5 MB**, less than 84.41% of C++ online submissions for Spiral Matrix.

+ Set the directions to move x and y accordingly


### Approach 2: Layer-by-Layer
Time: O(N); Space: O(N)

Runtime: **4 ms**, faster than 83.70% of C++ online submissions for Spiral Matrix.

Memory Usage: **8.7 MB**, less than 32.14% of C++ online submissions for Spiral Matrix.

+ traverse through all the elements for each layer from the outermost layer to the innermost layer

## 55. Jump Game
We call a position in an array a "good index" if starting from this position, we can reach the last index. Otherwise, the position is called a "bad index".
### Approach 1: Brute Force
Time Limit Exceeded

+ Find the good index at current stage and update other indices if they can reach the good index. Stop the loop if there is no more new good index

### Approach 2: Backtracking
Time Limit Exceeded

+ We start from the first position and jump to every index that is reachable. Repeat this process until we reach the last index. When stuck, backtrack.
+ We only jumps to the positions on the right side, since starting from the first index ensures that the leftmost position is covered

### Approach 3: Backtracking + Dynamic Programming
Time: O(N^2) Space: O(N) = Recursion cost + memorization table

+ Build a memorizatio table that records whether a specific position can reach the last index
+ Good, Unknown, Bad


### Approach 4: Greedy
Time: O(N); Space: O(1)

Runtime: **16 ms**, faster than 33.57% of C++ online submissions for Jump Game.

Memory Usage: **9.9 MB**, less than 54.82% of C++ online submissions for Jump Game.

+ Traverse the array from right to the left
+ Update the maximum reach and stop if we cannot move further



## 56. Merge Intervals

### Approach 1: Sorting
Time: O(NlogN); Space: O(1)

Runtime: **16 ms**, faster than 80.08% of C++ online submissions for Merge Intervals.

Memory Usage: **12.5 MB**, less than 16.76% of C++ online submissions for Merge Intervals.

+ Sort the intervals based on the the left element. Merge the adjacent intervals if the `a[i-1][1]` > `a[i][0]`


### Approach 2: Connected Components
Time: O(N^2); Space: 

Time Limit Exceeded


+ Build a undirected graph that connects every overlapping intervals
+ DFS for the graph and merge the intervals 


## 62. Unique Paths
### Approach 1: DFS
Runtime: **0 ms**, faster than 100.00% of C++ online submissions for Unique Paths.

Memory Usage: **8.7 MB**, less than 29.44% of C++ online submissions for Unique Paths.

+ dfs
+ memorization table for the number of unique paths of that position


## 63. Unique Paths2
### Approach 1: DFS +DP

Time: O(M\*N); Space: O(1)


Runtime: **0 ms**, faster than 100.00% of C++ online submissions for Unique Paths II.

Memory Usage: **9.4 MB**, less than 19.76% of C++ online submissions for Unique Paths II.

+ Add constrains based on Unique Paths


## 64. Minimum Path Sum
### Approach 1: Dyanmic Programming
Time: O(M\*N); Space: O(M\*N)

Runtime: **8 ms**, faster than 94.66% of C++ online submissions for Minimum Path Sum.

Memory Usage: **10.8 MB**, less than 47.14% of C++ online submissions for Minimum Path Sum.

+ Note that `INT8_MAX` equals to 127, and thus use `INT_MAX` instead


## 73. Set Matrix Zeroes
### Approach 1: Additional Memory Approach
Time: O(M\*N); Space: O(M + N)

Runtime: **44 ms**, faster than 96.07% of C++ online submissions for Set Matrix Zeroes.

Memory Usage: **11.5 MB**, less than 41.89% of C++ online submissions for Set Matrix Zeroes.


+ Record the row and column that needs to be changed

### Approach 2: Dummy Value
Time: O(M\*N\* (M+ N)); Space: O(1)

Runtime: **44 ms**, faster than 96.07% of C++ online submissions for Set Matrix Zeroes.

Memory Usage: **11.4 MB**, less than 83.83% of C++ online submissions for Set Matrix Zeroes.

+ Set the element to a dummy value which is chosen dependend on the constrains of the problem and keep the zero elemenet zero because we need to use them to find rows and columns needing altered 

### Approach 3: Flag
Time: O(M\* N); Space: O(1)

Runtime: **44 ms**, faster than 96.07% of C++ online submissions for Set Matrix Zeroes.

Memory Usage: **11.4 MB**, less than 76.65% of C++ online submissions for Set Matrix Zeroes.

+ Instead of recording rows and columns using additional memory structure, use the first element in the specific row or column as the flag to indicate whether this row or column should be reset.



## 75. Sort Colors
### Approach 1: Two pointer
Time: O(N); Space: O(1)

Runtime: **4 ms**, faster than 84.91% of C++ online submissions for Sort Colors.

Memory Usage: **8.5 MB**, less than 66.76% of C++ online submissions for Sort Colors.

+ Move two points inside and keep `k` in the range of `[i, j]`

## 77. Combinations
### Approach 1: Backtracking

Runtime: **76 ms**, faster than 77.13% of C++ online submissions for Combinations.

Memory Usage: **17.3 MB**, less than 29.10% of C++ online submissions for Combinations.

+ Create a memorization vector that records the current elements. 
+ Do not swap the list, since we are not going to reuse the same element.

### Approach 2: Iteration
Runtime: **68 ms**, faster than 85.15% of C++ online submissions for Combinations.

Memory Usage: **11.5 MB**, less than 96.75% of C++ online submissions for Combinations.

+ Work on current positions, and move on if necessary.
+ start -> `[1]` -> `[1, 1]` -> `[1, 2]`(ok) -> ... -> `[1, 4]`(ok) -> `[1, 5]`(5>4, --i) -> `[2]` -> `[2, 2]` -> `[2, 3]`(ok) -> ... -> `[2, 4]`(ok) -> `[2, 5]`(5>4, --i) -> `[3]` -> `[3, 3]` -> `[3, 4]`(ok) -> `[3, 5]`(5>4, --i) -> `[4]` -> `[4, 5]`(5>4, --i) -> `[5]`(5>4, --i) -> `[]` -> end


## 78. Subsets

### Approach 1: Backtracking with Pruning
Runtime: **4 ms**, faster than 98.92% of C++ online submissions for Subsets.

Memory Usage: **17.7 MB**, less than 5.68% of C++ online submissions for Subsets.

+ **specify the size of subset**
+ Add the current element or not (2 possible cases)
+ Pruning cases: the remaining numbers are not enough to form a subset of size k

### Approach 2: General Backtracking
Runtime: **8 ms**, faster than 78.49% of C++ online submissions for Subsets.

Memory Usage: **9 MB**, less than 84.32% of C++ online submissions for Subsets.

+ Finding all subsets with size k is inefficient. Directly try all the possible cases with one single subset variable.
+ push + pop


### Approach 3: Iteration
Runtime: **8 ms**, faster than 78.49% of C++ online submissions for Subsets.

Memory Usage: **9.1 MB**, less than 58.71% of C++ online submissions for Subsets.

Using [1, 2, 3] as an example, the iterative process is like:

1. Initially, one empty subset [[]]
2. Adding 1 to []: [[], [1]];
3. Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
4. Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].

### Approach 4: Bit Manupulation
Time: O(N \* 2^N)

Runtime: **4 ms**, faster than 98.92% of C++ online submissions for Subsets.

Memory Usage: **8.8 MB**, less than 99.48% of C++ online submissions for Subsets.

+ For `res[i]`, if i is 13=01101, then `res[i]` contains `nums[0]`, `nums[2]` and `nums[3]`

## 79. Word Search
### Approach 1: DFS
Runtime: **376 ms**, faster than 8.48% of C++ online submissions for Word Search.

Memory Usage: **57.6 MB**, less than 36.68% of C++ online submissions for Word Search.

+ Find whether a path which follows a specific rule on the map exists or not
+ Reset the `path` table if current point cannot form the final path

### Approach 2: DFS using Set
Runtime: **212 ms**, faster than 37.13% of C++ online submissions for Word Search.

Memory Usage: **91.3 MB**, less than 33.61% of C++ online submissions for Word Search.

+ Use set to store the `path` table

### Approach 3: Optimized DFS
Runtime: **24 ms**, faster than 90.21% of C++ online submissions for Word Search.

Memory Usage: **10 MB**, less than 88.38% of C++ online submissions for Word Search.

+ No need for extra memorization table for `path`, since we can change the content in the original map. Note that we do not need to restore the altered map because the LeetCode does not check our code with the old board.
+ **Use char pointer rather than string in the function argument to save both the time and space**

