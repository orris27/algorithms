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
    void backtrack(vector<string>& vs, string curr,int n, int left=0, int right=0)
    {
        if (left == n && right == n)
            vs.push_back(curr);
        else
        {
            if (left < n)
                backtrack(vs, curr + '(', n, left + 1, right);
            if (right < left) 
                backtrack(vs, curr + ')', n, left, right + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n);
        return res;
    }
};


int main()
{
    Solution so;
    vector<string> res;
    int n = 3;
    res = so.generateParenthesis(n);
    for (int i =0 ;i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

}
