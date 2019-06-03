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
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return 1;
        int l=0, r, max_length=0, index;
        map<char, int> chars; // char -> current max index
        chars.insert(pair<int, int>(s[0], 0));
        
        for (r=1;r<s.length();++r)
        {
            if (chars.find(s[r]) == chars.end()) // character that not appear in map
            {
                chars.insert(pair<char, int>(s[r], r));
            }
            else // character has already appeared in map
            {
                l = max(chars.find(s[r])->second + 1, l); // filter out elements with subscripts less than l
                chars.find(s[r])->second = r; // update
                //++l;
            }
            max_length = max(max_length, r - l + 1);
        }
        
        return max_length;
    }
};

int main()
{
    Solution so;
    string s;
    for (int i = 0; i < 4;++i)
    {
    
        cin >> s;
        cout << so.lengthOfLongestSubstring(s) << endl;
    }
    cout << so.lengthOfLongestSubstring(" ") << endl;

}
