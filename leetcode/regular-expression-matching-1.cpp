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
    bool isMatch(string s, string p)
    {
        if (p.length() == 0)
            return (s.length() == 0);
        bool first_match = (s[0] == p[0] || p[0] == '.');
        if (s.length() == 0)
            first_match = false;
        if (p.length() >= 2 && p[1] == '*')
        {
            if (isMatch(s, p.substr(2, p.length() - 2)) == true)
                return true;
            else
                return first_match && isMatch(s.substr(1, s.length() - 1), p);
        } 
        else
            return first_match && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));

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
