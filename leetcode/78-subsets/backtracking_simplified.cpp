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

class Solution {
public:
    void subsets(const vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int curr_index) {
        // start from current subset and index
        res.push_back(curr);
        for (int i=curr_index;i<nums.size();++i)
        {
            //  we add a single element and track 
            curr.push_back(nums[i]); 
            subsets(nums, res, curr, i + 1);
            curr.pop_back(); // simply remove the element. There is no need for new sub-routine followed, because this function only tests the case where curr plus a single remaining element
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        subsets(nums, res, curr, 0);
        return res;
    }
};
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

int main()
{
    Solution so;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so.subsets(nums);
    print(res);


}
