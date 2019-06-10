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
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right, l=0, r=nums.size()-1, mid;
        vector<int> res;
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        while(l < r) // find the leftmost element
        {
            mid = (l + r) / 2;
            if(nums[mid] >= target) r = mid; else l = mid + 1; // search its left side
        }
        if (nums[l] == target)
            res.push_back(l);
        else
            return vector<int>{-1, -1};
        l = 0;
        r = nums.size() - 1;
        while(l < r) // find the element that is just larger than target
        {
            mid = (l + r)/  2;
            if(nums[mid] <= target) l = mid + 1; else r = mid; // search its right side
        }
        if (nums[l] == target)
            res.push_back(l);
        else if (l - 1 >= 0 && nums[l - 1] == target)
            res.push_back(l - 1); 
        return res;
    }
};

void print(vector<int> v)
{
    for (int i=0;i<v.size();++i)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    Solution so;
    vector<int> v{5, 7, 7, 8, 8, 10};
    print(so.searchRange(v, 8));
    print(so.searchRange(v, 6));

    v = {2};
    print(so.searchRange(v, 1));
    print(so.searchRange(v, 2));

}
