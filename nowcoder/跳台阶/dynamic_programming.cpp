class Solution {
public:
    static const int N = 1e5+10;
    int dp[N];
    int jumpFloor1(int number){
        if (number == 0)
            return dp[number] = 1;
        if (number == 1)
            return dp[number] = 1;
        if (dp[number] != -1)
            return dp[number];
        return dp[number] = jumpFloor1(number - 1) + jumpFloor1(number -2);
         
    }
    int jumpFloor(int number) {
        memset(dp, -1, sizeof(dp[0])*N);
        for(int i =0;i<=number;++i)
            jumpFloor1(i);
        return dp[number];
    }
};

