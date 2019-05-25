## 1. Building Palindromes
### Points
+ At most one character can appear odd number of times
+ Count the frequencies of each character in the sub-string faster: Record the prefix sum of the frequencies for each character

### Complexity
`O((N + Q) * |character set|)`

## 2. Energy Stones
### Points
+ 0/1 knapsack problem: `dp[i][j]` represents the maximum total energy that can be achieved given first i items and j seconds. Note that the j seconds should include the time of eating, that is if an energy stone is 's=12, e=300, l=50', then `dp[1][0:11]=0;dp[1][12]=300;dp[1][12]=250`
+ loss => comparison metrics
    - All stones take the same amount of time to eat: Consider two stones i and j that will be eaten back-to-back, if L_i > L_j, then we should eat i before j
    - General Case: Consider two stones i and j, if S_i * L_j > S_j * L_i, then we should eat i before j. Note that we assume that we can take both of them without either going to zero energy.




