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

void print_v(vector<int> v)
{
    for(int i :v)
        cout << i << " ";
    cout << endl;

}
void print(vector<vector<int>> vv)
{
    for(auto v: vv)
    {
        for(int i: v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

}



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (int i =0;i<nums.size();++i)
        {
            int n = res.size();
            for(int j=0;j<n;++j)
            {
                vector<int> tmp(res[j].begin(), res[j].end());
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }


        
        return res;
    }
};
int main()
{
    Solution so;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so.subsets(nums);
    print(res);


}
