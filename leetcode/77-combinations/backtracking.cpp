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
    // curr: current elements; k: required total number; start: where should we pick element in nums array
    void backtrack(vector<vector<int>>& res, const vector<int>& nums, vector<int> curr, int k, int start) {
        if (curr.size() == k) // if we have stored enough number of elements
        {
            res.push_back(curr);
            return;
        }
        int n=nums.size(), cn=curr.size();
        int remain = k - cn; // remaining number

        for (int i=start;i + remain<=n;++i) // iterations starts from `start` position, because we do not use the previous elements for the remaining `remain` number of elements to avoid same element
        {
            curr.push_back(nums[i]);
            backtrack(res, nums, curr, k, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n), curr;
        iota(nums.begin(), nums.end(), 1);
        vector<vector<int>> res;
        
        backtrack(res, nums, curr, k, 0);
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
