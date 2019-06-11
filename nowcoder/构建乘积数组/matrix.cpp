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
    vector<int> multiply(const vector<int>& A) {
        //vector<int> res(1, A.size());
        int tmp = 1, n=A.size();
        vector<int> res(n, 1);
        for (int i =0;i<n;++i)
        {
            res[i] *= tmp;
            tmp *= A[i];
        }
        tmp = 1;
        for (int i = n-1;i>=0;--i)
        {
            res[i] *= tmp;
            tmp *= A[i];
        }
        return res;
    }
};

void print(vector<int> v)
{
    for(int i =0;i<v.size();++i)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    Solution so;
    vector<int> v{1, 2, 3, 4, 5};
    print(so.multiply(v));


}
