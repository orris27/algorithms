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



const int N = 1e5;
int good[N]; // 1: good; 0: unknown; -1: bad
class Solution {
public:
    int canJumpFromPosition(vector<int>& nums, int pos)
    {
        int n = nums.size();
        if (good[pos] != 0)
            return good[pos];
        // We only need to check the right side, because we start from the starting point which means that we will cover the leftmost possible index
        //        Since we can 
        int range = min(n - 1 - pos, nums[pos]); // how far we can jump
        for (int i=range; i >= 1;--i)
        {
            if (canJumpFromPosition(nums, pos+i) == 1)
                return good[pos] = 1;
        }
        return good[pos] = -1;
    }
    bool canJump(vector<int>& nums) {
        memset(good, 0, sizeof(good[0]) * nums.size());
        good[nums.size() - 1] = 1;
        return canJumpFromPosition(nums, 0) == 1;
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
