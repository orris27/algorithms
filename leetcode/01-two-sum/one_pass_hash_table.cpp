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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int>::iterator it;
        map<int, int> num2idx;
        for (int i =0 ;i<nums.size();++i)
        {
            it = num2idx.find(target - nums[i]);
            if(it != num2idx.end())
                return vector<int>{it->second, i};
            
            num2idx.insert(pair<int, int>(nums[i], i));
        }
        return res;
        
    }


};

int main()
{
    Solution so;
    vector<int> nums{2, 7, 11, 15};
    vector<int> res;
    res = so.twoSum(nums, 22);
    for (int i =0 ;i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

}
