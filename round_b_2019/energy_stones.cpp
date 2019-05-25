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


//const int N = 105;
const int N = (int) 2e4 + 4;
int s[N];
int e[N];
int l[N];
int o[N];
int dp[100005]; // dp[i][j]: the max amount of energy given j seconds and first i items. Note that the first i items must be fully eaten in j seconds
int odp[100005];

int cmp(int a, int b)
{
    //int va = -1 * l[b];
    int va = e[a] + e[b] - s[a] * l[b];
    //int vb = -1 * l[a];
    int vb = e[b] + e[a] - s[b] * l[a];
    return va > vb;
}

int main()
{
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt)
    {
        
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i] >> e[i] >> l[i];
            o[i] = i;
        }
        sort(o, o + n, cmp);
        memset(dp, 0, sizeof(dp));
        memset(odp, 0, sizeof(odp));
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int index = o[i];
            sum += s[index];

            //for (int secs = sum - s[index]; secs <= sum; ++secs)
            //    dp[secs] = dp[sum - s[index]];

            for (int secs = 0; secs <= sum; ++secs)
                odp[secs] = dp[secs];

            for (int secs = s[index]; secs <= sum; ++secs)
            {
                int en = e[index] - (secs - s[index]) * l[index]; //!!! e[index], not s[index]
                if (en <= 0) 
                    continue;
                dp[secs] = max(odp[secs], odp[secs - s[index]] + en); // !!! odp[secs - s[index]], not dp[secs - s[index]]
            }
        }
        int res = 0;
        for (int i = 0; i < N; ++i) res = max(res, dp[i]); // !!! select the max item in the dp array, rather than dp[sum]
        //int res = dp[sum];
        cout << "Case #" << tt << ": " << res << '\n';
        

    }
    
}
