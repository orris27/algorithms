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
#include <numeric>

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
	vector<vector<int>> combine(int n, int k) {
        int curr_pos=0;
        vector<vector<int>> res;
        vector<int> curr(k, 0);
        while(curr_pos>=0)
        {
            curr[curr_pos]++; // e.g.: [1, 3, 3, ?] ~ [1, 3, 8, ?] when n=8
            if (curr[curr_pos] > n) --curr_pos; // if it is larger than the maximum value, it means [1, curr_pos-1] combination is finished
            else if(curr_pos + 1 == k) res.push_back(curr); 
            else
            {
                ++curr_pos; // intermedia state
                curr[curr_pos] = curr[curr_pos - 1];
            }
        }
        return res;
	}
};

void print(vector<vector<int>> res)
{
    for (auto v: res)
    {
        for(int i: v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

}

int main()
{
    Solution so;
    vector<vector<int>> res = so.combine(4, 2);
    print(res);
    


}
