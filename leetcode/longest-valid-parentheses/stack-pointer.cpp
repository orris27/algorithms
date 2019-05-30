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
    int longestValidParentheses(string s) {
        if (s.length() <= 1)
            return 0;
        int max_length = 0, top, right, curr;
        
        for (int i=0;i<s.length() - 1; ++i)
        {
            top = 0;
            curr = i;
            right = i;
            if (s[i] == ')')
                continue;
            do{
                if (s[curr] == '(')
                    ++top;
                else
                    --top;
                curr += 1;
                if (top == 0)
                    right = curr;
            }while(top >= 0 && curr < s.length());
            max_length = max(max_length, right - i);
        
        }
        return max_length;
    }
};

int main()
{
    Solution so = Solution();
    string s;
    cin >> s;
    cout << so.longestValidParentheses(s) << endl;
    

}


