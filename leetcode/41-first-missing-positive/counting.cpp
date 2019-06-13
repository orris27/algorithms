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
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        // traverse all elements, put the element in the right place by swapping (a[0] = 1, a[1] = 2, etc)
        for(int i =0; i< nums.size();++i)
            while(i + 1 != nums[i] && nums[i] - 1 >= 0 && nums[i] - 1 < nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        // find the element that is not equal to its position
        for (int i =0;i<nums.size(); ++i)
            if(i + 1 != nums[i])
                return i + 1;
        return nums.size() + 1;
    }
};


int main()
{
    Solution so;
    vector<int> nums{1, 2, 0};
    cout<<so.firstMissingPositive(nums)<<endl;
    nums = {3, 4, -1, 1};
    cout<<so.firstMissingPositive(nums)<<endl;
    nums = {7, 8, 9, 11, 12};
    cout<<so.firstMissingPositive(nums)<<endl;
}
