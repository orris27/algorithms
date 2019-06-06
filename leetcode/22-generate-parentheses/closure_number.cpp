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
    vector<string> generateParenthesis(int n) {
        vector<string> res, left, right;
        if (n == 0)
            return res;
        if (n == 1)
        {
            res.push_back("()");
            return res;
        }

        for (int i =0;i<n; ++i)
        {
            left = generateParenthesis(i);
            right = generateParenthesis(n - i - 1);
            if (left.size() == 0)
                left.push_back("");
            if (right.size() == 0)
                right.push_back("");

            for (int l=0;l < left.size();++l)
                for (int r =0;r < right.size();++r)
                {
                    string s="(" + left[l] +")" +right[r];
                    res.push_back(s);
                }
        }
        
        return res;
    }
};


int main()
{
    Solution so;
    vector<string> res;

    res = so.generateParenthesis(0);
    cout << 0 << ": ";
    for (int i =0 ;i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

    res = so.generateParenthesis(1);
    cout << 1 << ": ";
    for (int i =0 ;i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

    res = so.generateParenthesis(2);
    cout << 2 << ": ";
    for (int i =0 ;i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

    res = so.generateParenthesis(3);
    cout << 3 << ": ";
    for (int i =0 ;i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
}
