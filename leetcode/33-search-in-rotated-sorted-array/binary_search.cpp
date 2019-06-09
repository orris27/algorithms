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
    int search(vector<int>& nums, int target) {
        int n=nums.size(), left=0, right=n-1, mid, lshift, rshift;
        if (n == 0) return -1;
        if (n == 1) return (nums[n - 1] == target)?0:-1;
        
        // find the first "i" that is less than nums[0], otherwise n - 1: binary search
        while(left < right)
        {
            mid = (left + right) / 2;
            if (nums[0] <= nums[mid]) left = mid + 1; else right = mid; // if they are same, move to the left
        }
        int pivot = (left == n - 1 && nums[left] > nums[0]) ? left + 1:left; // avoid the case that the array is not rotated, such as [1, 3]. Since in this case we will always get left==n-1
        
        left = 0;
        right = n- 1;
        while(left < right) // binary search for target
        {
            mid = (left + right) / 2;
            if (target <= nums[(mid + pivot) % n]) right = mid; else left = mid + 1; // remainder to determine position 
        }
        return (nums[(left + pivot) % n] == target)?(left + pivot) % n:-1;
    }
};



int main()
{
    Solution so;
    vector<int> nums{4,5,6,7,0,1,2};
    cout << so.search(nums, 0) << endl;
    cout << so.search(nums, 3) << endl;

    nums = {1, 3};
    cout << so.search(nums, 0) << endl;
    cout << so.search(nums, 1) << endl;
    cout << so.search(nums, 3) << endl;


    nums = {3, 1};
    cout << so.search(nums, 1) << endl;


    nums = {1};
    cout << so.search(nums, 0) << endl;
    cout << so.search(nums, 1) << endl;


    nums = {1, 3, 5};
    cout << so.search(nums, 0) << endl;
}

