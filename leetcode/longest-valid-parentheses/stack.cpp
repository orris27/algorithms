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
        int max_length = 0, left;
        stack<int> st;
        st.push(-1);
        for (int i =0;i< s.length(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty() == true)
                {
                    st.push(i);
                }
                left = st.top(); // !!! pick the topmost element after empty check
                max_length = max(max_length, i - left);
            }
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


