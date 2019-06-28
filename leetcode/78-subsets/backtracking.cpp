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
    void add_subsets_k(vector<vector<int>>& res, const vector<int>& nums, vector<int> curr, int k, int curr_index) {
        // k: size of required size
        // curr_index: current position in nums, add or not add
        int n=nums.size(), cn=curr.size();
        //debug("k: %d, curr_index: %d; cn: %d; n: %d\n", k, curr_index, cn, n);
        //print_v(curr);
        if (cn == k) res.push_back(curr);
        if (cn == k || (cn + n - curr_index) < k || curr_index + 1 > n) // reach the required size || the remaining numbers are not enough to form a subset with size k || curr_index is out of bounds
            return;
        // not add current value
        if (cn + n - curr_index != k) // we can reach the list with size k if and only if we use all the remaining numbers, which menas that we must add current element
            add_subsets_k(res, nums, curr, k, curr_index+1);
        // add current value
        //debug("new element: %d; curr_index: %d; n: %d\n", nums[curr_index], curr_index, n);
        curr.push_back(nums[curr_index]);
        add_subsets_k(res, nums, curr, k, curr_index + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        for (int i=0;i<=nums.size();++i)
            add_subsets_k(res, nums, curr, i, 0);
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
