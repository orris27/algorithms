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
        int n = nums.size();
        vector<bool> ok(n, false);
        //print_v(ok);

        // The termination condition of the loop is that ok array is no longer updated and the loop guarantees to reach the termination condition after n number of iterations.
        
        //for (int k=0;k<n;++k) 
        ok[n-1] = true;
        while (true)
        {
            bool break_flag = true;
            for (int i= n - 1;i >= 0;--i) // starting from the last index can update more positions in one loop
            {
                if (ok[i] == true)
                {
                    for(int j = n - 1;j >= 0;--j)
                    {
                        //debug("i: %d || j: %d\n", i, j);
                        if (ok[j] == false && nums[j] >= abs(i - j)) // j can reach i 
                        {
                            ok[j] = true;
                            break_flag = false;
                        }
                    }
                }
            }
            if (break_flag == true)
                break;
        }
        return ok[0];
            
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
