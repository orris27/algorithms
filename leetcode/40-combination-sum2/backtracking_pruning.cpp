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
    void combinationSum2(vector<int> & candidates, int target, vector<vector<int>>& res, int index, vector<int> tmp_list)
    {
        if(target == 0)
            res.push_back(tmp_list);
        if (index >= candidates.size() || target < candidates[index])
            return;

        // calculate numbers of same elements
        int nums = 0;
        for(int i=index;i<candidates.size() && candidates[i] == candidates[index];++i, ++nums);

        for (int i =0; i <= nums;++i)
        {
            if(i!=0)
                tmp_list.push_back(candidates[index]);
            combinationSum2(candidates, target - candidates[index] * i, res, index + nums, tmp_list);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp_list;
        sort(candidates.begin(), candidates.end()); // sort in ascending order, to perform pruning
        combinationSum2(candidates, target, res, 0, tmp_list);
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
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = so.combinationSum2(candidates, 8);
    print(res);

    candidates = {2, 5, 2, 1, 2};
    res = so.combinationSum2(candidates, 5);
    print(res);

}
