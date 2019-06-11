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
    for(int i =0;i<v.size();++i)
        cout << v[i] <<" ";
    cout << endl;
}

class Solution {
public:
    void combinationSum1(vector<vector<int>> &res, vector<int> candidates, int index, vector<int> tmp_list, int target)
    {
        if (target == 0) // tmp_listent list satisfies the meets
            res.push_back(tmp_list);
        if(index >= candidates.size() || target <= 0) // index is larger than the size
            return;

        int nums = target / candidates[index]; // compute the maximum possible numbers of tmp_listent element
            
        for (int i = 0;i <= nums;++i) // !!! do not make mistakes on ++i and --i 
        {
            if (i >= 1) // append "i" number of tmp_listent element to "tmp_list" 
                tmp_list.push_back(candidates[index]); // note that we append exactly one element to the tmp_list because if we append "i" number of elements, the "tmp_list" would end up with "1+2+3+...+nums" elements
            combinationSum1(res, candidates, index + 1, tmp_list, target - i * candidates[index]);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp_list;
        combinationSum1(res, candidates, 0, tmp_list, target);
        return res;
    }
};


void print(const vector<vector<int>>& vv)
{
    vector<int> v;
    for (int i =0; i<vv.size();++i)
    {
        v = vv[i];
        for (int j =0 ;j<v.size();++j)
            cout << v[j] << " ";
        cout << endl;
    }
}


int main()
{
    Solution so;
    vector<int> candidates{2, 3, 6, 7};
    vector<vector<int>> res = so.combinationSum(candidates, 7);
    print(res);

    candidates = {2, 3, 5};
    res = so.combinationSum(candidates, 8);
    print(res);

}
