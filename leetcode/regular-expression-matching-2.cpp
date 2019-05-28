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

//const int N = 2e4 + 5;
const int N = 100;

int dp[N][N];
class Solution {
public:
    bool isMatch(string s, string p, int ss, int ps)
    {
        if (dp[ss][ps] != -1)
            return dp[ss][ps];
        if (ps == p.length())
            return dp[ss][ps] = (ss == s.length());

        bool first_match = (s[ss] == p[ps] || p[ps] == '.');

        if (ss == s.length())
            first_match = false;
        if (ps + 2 <= p.length() && p[ps + 1] == '*')
        {
            if (isMatch(s, p, ss, ps + 2) == true)
            {
                return dp[ss][ps] = true;
            }
            else
                return dp[ss][ps] = (first_match && isMatch(s, p, ss + 1, ps));
        }
        else
            return dp[ss][ps] = (first_match && isMatch(s, p, ss + 1, ps + 1));
    }
    bool isMatch(string s, string p)
    {
        memset(dp, -1, sizeof(dp[0][0]) * N * N);
        return isMatch(s, p, 0, 0);
    }
};


int main()
{
    Solution so = Solution();
    string s, p;
    cin >> s;
    cin >> p;
    cout << so.isMatch(s, p) << endl;
    


}
