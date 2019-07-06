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
    vector<int> countBits(int num) {
        int first_0=0, count;
        vector<int> res{0};
        for (int i=1;i<=num;++i)
        {
            if ((i-1) & 1 == 0) // the last bit of the previous element is equal to 0
            {
                res.push_back(res[i-1] + 1);
            }
            else 
            {
                count = 0;
                for (int j=0;j<32;++j)
                {
                    if ((i >> j)&1 == 1) // this bit is 1
                        ++count;
                }
                res.push_back(count);
            
            }
        }
        return res;
    }
};

void print(vector<int> v)
{
    for (auto elm: v)
        cout << elm << " ";
    cout << endl;

}

int main()
{
    Solution so;
    vector<int> res = so.countBits(2);
    print(res);
    res = so.countBits(5);
    print(res);
    


}
