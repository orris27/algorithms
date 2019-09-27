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
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        int len = strs[0].length(); // larger than the size of common prefix
        int index = 0;
        for (int i =0;i<len;++i)
        {
            for(int j = 1;j<strs.size();++j)
            {
                if(i >= strs[j].length() || strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, index);
                }
            }
            ++index;
        }
        return strs[0].substr(0, index);
    }
};



int main()
{
    vector<string> strs = {"flower","flow","flight"};
    Solution so;
    string prefix = so.longestCommonPrefix(strs);
    printf("%s\n", prefix.c_str());
}
