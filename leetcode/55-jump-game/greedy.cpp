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


void print_v(vector<bool> res)
{
    for (int i=0;i<res.size();++i)
        cout << res[i] << " ";
    cout << endl;

}



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i=0;i<nums.size() && i <= reach; ++i) // we expand our reach while moving to the right and stop if we cannot move on
        {
            reach = max(i + nums[i], reach); // if the current position can jump further, update reach
            if (reach >= nums.size() - 1) return true;
        }
        return false;
    }
};


int main()
{
    Solution so;
    vector<int> nums{2, 3, 1, 1, 4};
    cout << so.canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << so.canJump(nums) << endl;
}
