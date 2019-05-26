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


const int N = 1e5 + 10;
int freq[N][26];
int main()
{
    int tc;
    cin >> tc;
    for (int idx = 1; idx <= tc; ++ idx)
    {
        cout << "Case #" << idx << ": ";
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < 26; ++i)
            {
                freq[j + 1][i] = freq[j][i] ^ (s[j] == i + 'A'); // freq[j][i]: 1 if char i occurs odd number of times in s[0:j + 1] else 0. Therefore j is inclusive
            }
            
        }
        
        int count = 0;
        int l, r;
        for (int i = 0; i < q; ++i)
        {
            cin >> l >> r;
            int num = 0;
            for (int ch = 0; ch < 26; ++ch)
            {
                num += freq[r][ch] ^ freq[l - 1][ch]; // odd - odd => even; even - even => even; odd - even => odd; even - odd => odd
            }
            if (num <= 1)
              ++count;
        }
        cout << count << endl;
    
    }


}
