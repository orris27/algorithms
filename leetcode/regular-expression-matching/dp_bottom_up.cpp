/*
 * Bottom-Up
 */
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


/*
1. if p[j] is '*'
    dp[i][j] = false;
2. s is emtpy
    if j == p.length() - 1: dp[i][j] = false;
    else
        if p[j+1] == '*' and j + 1 == length() - 1:
            dp[i][j] = true;
        else
            dp[i][j] = fasle;
3. s is not empty
    if match
        if dp[i][j] = dp[i][j+2] || dp[i+1][j]
    else 
        dp[i][j] = dp[i][j+2]
        
*/



//const int N = 2e4 + 5;
const int N = 100;


bool dp[N][N];
class Solution {
public:
    bool isMatch(string s, string p)
    {
        memset(dp, 0, sizeof(dp[0][0]) * N * N);
        dp[s.length()][p.length()] = true; // if both are empty, then they match
        for (int i=s.length();i>=0;--i)
            for (int j=p.length() - 1;j>=0;--j)
            {
                if (p[j] == '*') 
                    dp[i][j] = false;
                else if (i == s.length()) // s[i:] is empty
                {

                    if (j + 1 < p.length() && p[j + 1] == '*') // if p[j+1] exists and it is '*'
                    {
                        dp[i][j] = dp[i][j+2];
                    }
                    else
                        dp[i][j] = false;
                }
                else // s[i:] is not empty
                {
                    if (j + 1 < p.length() && p[j + 1] == '*') // if p[j+1] exists and it is '*'
                    {
                        if (s[i] == p[j] || p[j] == '.')
                            dp[i][j] = dp[i][j+2] || dp[i + 1][j];
                        else
                            dp[i][j] = dp[i][j+2];
                    }
                    else
                    {
                        if (s[i] == p[j] || p[j] == '.')
                            dp[i][j] = dp[i+1][j+1];
                        else 
                            dp[i][j] = false;
                    }
                }
            }

        return dp[0][0];
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
