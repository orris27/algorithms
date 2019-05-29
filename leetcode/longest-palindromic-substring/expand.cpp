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
        string longestPalindrome(string s) {
            if (s.length() == 1)
                return s;
            int len = s.length();
            int left, right;
            string res = s.substr(0, 1);

            for (int i =1;i<len - 1;++i) // odd case
            {
                // expand 
                left = i;
                right = i;
                while(left - 1 >= 0 && right + 1 < len && s[left - 1] == s[right + 1])
                {
                    --left;
                    ++right;
                }
                if (res.length() < (right - left + 1))
                {
                    res = s.substr(left, right - left + 1);
                }
            }
            for (int i =0;i<len - 1;++i) // even case
            {
                // expand 
                left = i;
                right = i + 1;
                while(left >= 0 && right < len && s[left] == s[right])
                {
                    --left;
                    ++right;
                }
                ++left; // adjust
                --right; // adjust
                if (res.length() < (right - left + 1))
                {
                    res = s.substr(left, right - left + 1);
                }
            }

            return res;
        }


};

int main()
{
    string s;
    cin >> s;
    Solution so = Solution();
    cout << so.longestPalindrome(s) << endl;

}
