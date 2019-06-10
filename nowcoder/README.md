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


