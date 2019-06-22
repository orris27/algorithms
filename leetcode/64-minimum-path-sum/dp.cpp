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


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        dp[0][0] = grid[0][0];
        for(int i =0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
            {
                if (i == 0 && j == 0) continue;
                int top = (i - 1 >= 0)?dp[i - 1][j]:INT_MAX;
                int left = (j - 1 >= 0)?dp[i][j - 1]:INT_MAX;
                dp[i][j] = min(top, left) == INT8_MAX?INT8_MAX:min(top, left) + grid[i][j];
                
            }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};

int main()
{
    Solution so;
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << so.minPathSum(grid) << endl;

}
