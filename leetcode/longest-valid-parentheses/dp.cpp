#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;


const int N = 2e4 + 5;
int dp[N]; // dp[i]: length of longest valid parenthese ending at s[i]

class Solution {
public:
    int longestValidParentheses(string s) {
        int a, b, max_length = 0;
        memset(dp, 0, sizeof(dp[0]) * N);
        for (int i = 0;i < s.length(); ++i)
        {
            if (s[i] == '(' || i == 0)
                dp[i] = 0;
            else
            {
                if(s[i - 1] == '(')
                {
                    a = i - 2 >= 0?dp[i - 2]:0;
                    b = (i -2>=0 && i - dp[i-2] - 2 >= 0)? dp[i - dp[i-2] - 2] : 0;
                    dp[i] = a + b + 2;
                }
                else
                {
                    a = (i - dp[i-1] - 2 >= 0)? dp[i -dp[i-1] -2] : 0;
                    if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1]- 1] =='(')
                        dp[i] = dp[i-1] + 2 + a;
                    else
                        dp[i] = 0;
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
};


int main()
{
    Solution so = Solution();
    string s;
    for (int i =0 ;i<5; ++i)
    {
        cin >> s;
        cout << so.longestValidParentheses(s) << endl;
    }
}


