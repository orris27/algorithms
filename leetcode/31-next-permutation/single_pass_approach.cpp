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
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int size = nums.size();
        if (nums[size-1] > nums[size-2])
        {
            swap(nums[size-1], nums[size-2]);
            return;
        }

        // the first pair of two successive numbers a[i-1] and a[i], from the right, which satisfy a[i-1] < a[i]. Here most = i.
        int most=-1; 

        for (int i = nums.size()- 2;i>=0;--i)
            if (nums[i] < nums[i+1])
            {
                most = i + 1;
                break;
            }

        int index=size-1, elm=nums[index];

        if (most == -1) // reverse the vector
            for (int i = 0, j = size-1;i < j;++i, --j)
                swap(nums[i], nums[j]);
        else 
        {
            for (int i = most - 1;i<size -1;++i) // find the minimum element larger than nums[most-1]
                if (nums[i+1] <= nums[most-1])
                {
                    index = i;
                    elm = nums[i];
                    break;
                }
           
            swap(nums[most - 1], nums[index]);
            for (int i = most, j =size-1;i< j;++i, --j)
                swap(nums[i], nums[j]);
        }
    }
};


void test(Solution so, vector<int>& nums)
{

    for (int i =0 ;i < nums.size(); ++i)
        cout << nums[i] << " ";

    so.nextPermutation(nums);
    cout << "=> ";
    for (int i =0 ;i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;
}

int main()
{
    int a = 2, b = 3;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;

    Solution so;
    vector<int> nums{1, 2, 3};

    test(so, nums);
    
    nums = {1, 3, 2};
    test(so, nums);

    
    nums = {2, 1, 3};
    test(so, nums);

    nums = {2, 3, 1};
    test(so, nums);


    nums = {3, 1, 2};
    test(so, nums);


    nums = {3, 2, 1};
    test(so, nums);

}
