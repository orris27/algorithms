## 二维数组中的查找
### Approach 1: Brute Force

### Approach 2: Matrix Search
运行时间：**13ms**

占用内存：**1500k**

+ Start searching from bottom left corner of matrix. If the target is less than the current element, move up, otherwise move to the right.

## 替换空格
### Approach 1: Back to front
运行时间：**5ms**

占用内存：**596k**

+ Calculate number of spaces by iterating through the array forwards. Replace spaces starting from the last element to reduce the times of moving elements which is time-consuming.

## 用两个栈实现队列
### Approach 1: one stack one usage
运行时间：**4ms**

占用内存：**472k**

+ One stack is used for pushing, while another one is used for poping

## 跳台阶
### Approach 1: Dynamic Programming
运行时间：**4ms**

占用内存：**972k**

+ dp[0] = dp[1] = 1; dp[n] = dp[n - 1] + dp[n - 2];


## 字符流中的第一个不重复的字符
### Approach 1: Queue with counting
运行时间：**3ms**

占用内存：**620k**

+ Recording the sequence order using queue
+ Store the times of occurs for every character using array


## 构建乘积数组
### Approach 1: matrix approach
运行时间：**4ms**

占用内存：**468k**

| res[0] |      | A[1] | A[2] | A[3] | A[4] |
| ------ | ---- | ---- | ---- | ---- | ---- |
| res[1] | A[0] |      | A[2] | A[3] | A[4] |
| res[2] | A[0] | A[1] |      | A[3] | A[4] |
| res[3] | A[0] | A[1] | A[2] |      | A[4] |
| res[4] | A[0] | A[1] | A[2] | A[3] |      |


