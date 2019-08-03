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
    string addBinary1(string a, string b) {
        // a.length() < b.length()
        int c=0, curr;
        int i=a.length()-1, j=b.length()-1;
        string res(j + 1, '0'); // neglect the possible first character
        for (;i>=0;--i, --j)
        {
            curr = (a[i] - '0') + (b[j] - '0') + c;
            c = (curr >= 2)?1:0;
            res[j] = (curr % 2) + '0';
        }
        for (;j>=0;--j)
        {
            curr = (b[j] - '0') + c;
            c = (curr >= 2)?1:0;
            res[j] = (curr % 2) + '0';
        }
        if (c == 1) 
            res.insert(0, "1");
        return res;
    }
    string addBinary(string a, string b) {
        int l1=a.length(), l2=b.length();
        string res = (l1 < l2?addBinary1(a, b):addBinary1(b, a));
        return res;

    }
};

int main()
{
    Solution so;
    string a="11", b="1";
    cout << so.addBinary(a, b) << endl;
    a = "1010";
    b = "1011";
    cout << so.addBinary(a, b) << endl;


}
